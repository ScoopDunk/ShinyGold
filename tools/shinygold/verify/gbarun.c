// Headless mGBA harness: gbarun <rom> <script> [outdir]
// script commands (one per line):
//   wait N            run N frames with no keys
//   press KEYS N      hold keys (A,B,L,R,START,SELECT,UP,DOWN,LEFT,RIGHT joined by +) for N frames, then 1 release frame
//   hold KEYS N       hold keys for N frames (no release)
//   shot FILE         write PNG screenshot
//   save FILE / load FILE   savestate
//   r8/r16/r32 ADDR   print memory value
//   dump ADDR LEN FILE
//   loadsav FILE / writesav FILE  battery save
#include <mgba/core/core.h>
#include <mgba/core/log.h>
#include <mgba/core/serialize.h>
#include <mgba-util/vfs.h>
#include <png.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void nolog(struct mLogger* l, int c, enum mLogLevel lv, const char* f, va_list a){(void)l;(void)c;(void)lv;(void)f;(void)a;}
static struct mLogger logger={.log=nolog};
static uint32_t keymask(const char* s){
  uint32_t k=0; char buf[256]; strncpy(buf,s,255); buf[255]=0;
  for(char* t=strtok(buf,"+"); t; t=strtok(NULL,"+")){
    if(!strcmp(t,"A"))k|=1<<0; else if(!strcmp(t,"B"))k|=1<<1; else if(!strcmp(t,"SELECT"))k|=1<<2;
    else if(!strcmp(t,"START"))k|=1<<3; else if(!strcmp(t,"RIGHT"))k|=1<<4; else if(!strcmp(t,"LEFT"))k|=1<<5;
    else if(!strcmp(t,"UP"))k|=1<<6; else if(!strcmp(t,"DOWN"))k|=1<<7; else if(!strcmp(t,"R"))k|=1<<8; else if(!strcmp(t,"L"))k|=1<<9;
  }
  return k;
}
static color_t* vbuf; static unsigned W,H;
static void shot(const char* fn){
  FILE* f=fopen(fn,"wb"); png_structp p=png_create_write_struct(PNG_LIBPNG_VER_STRING,0,0,0); png_infop i=png_create_info_struct(p);
  png_init_io(p,f); png_set_IHDR(p,i,W,H,8,PNG_COLOR_TYPE_RGB,PNG_INTERLACE_NONE,PNG_COMPRESSION_TYPE_DEFAULT,PNG_FILTER_TYPE_DEFAULT);
  png_write_info(p,i); unsigned char* row=malloc(W*3);
  for(unsigned y=0;y<H;y++){ for(unsigned x=0;x<W;x++){ uint32_t c=vbuf[y*W+x]; row[x*3]=c&0xFF; row[x*3+1]=(c>>8)&0xFF; row[x*3+2]=(c>>16)&0xFF; } png_write_row(p,row);} 
  png_write_end(p,i); png_destroy_write_struct(&p,&i); fclose(f); free(row);
}
int main(int argc,char**argv){
  if(argc<3){fprintf(stderr,"usage\n");return 1;}
  mLogSetDefaultLogger(&logger);
  struct mCore* core=mCoreFind(argv[1]); if(!core){fprintf(stderr,"no core\n");return 1;}
  core->init(core); mCoreInitConfig(core,NULL);
  core->desiredVideoDimensions(core,&W,&H);
  vbuf=malloc(W*H*sizeof(color_t)); core->setVideoBuffer(core,vbuf,W);
  if(!mCoreLoadFile(core,argv[1])){fprintf(stderr,"load fail\n");return 1;}
  struct VFile* sav=VFileMemChunk(NULL,0); core->loadSave(core,sav);
  core->reset(core);
  FILE* sc=fopen(argv[2],"r"); char line[512];
  while(fgets(line,sizeof line,sc)){
    char cmd[32],a1[256],a2[256],a3[256]; int n=sscanf(line,"%31s %255s %255s %255s",cmd,a1,a2,a3);
    if(n<1||cmd[0]=='#')continue;
    if(!strcmp(cmd,"wait")){int fr=atoi(a1); core->setKeys(core,0); for(int i=0;i<fr;i++)core->runFrame(core);}
    else if(!strcmp(cmd,"press")||!strcmp(cmd,"hold")){int fr=n>2?atoi(a2):2; core->setKeys(core,keymask(a1)); for(int i=0;i<fr;i++)core->runFrame(core); if(!strcmp(cmd,"press")){core->setKeys(core,0); core->runFrame(core);} }
    else if(!strcmp(cmd,"shot")) shot(a1);
    else if(!strcmp(cmd,"save")){struct VFile* vf=VFileOpen(a1,O_CREAT|O_TRUNC|O_RDWR); mCoreSaveStateNamed(core,vf,SAVESTATE_SAVEDATA); vf->close(vf);}
    else if(!strcmp(cmd,"load")){struct VFile* vf=VFileOpen(a1,O_RDONLY); if(!vf){printf("noload %s\n",a1);continue;} bool ok=mCoreLoadStateNamed(core,vf,SAVESTATE_SAVEDATA); if(!ok)printf("loadstate failed\n"); vf->close(vf);}
    else if(!strcmp(cmd,"r8")){uint32_t a=strtoul(a1,0,0); printf("%s %08x = %02x\n",a2[0]&&n>2?a2:"",a,core->rawRead8(core,a,-1));}
    else if(!strcmp(cmd,"r16")){uint32_t a=strtoul(a1,0,0); printf("%08x = %04x\n",a,core->rawRead16(core,a,-1));}
    else if(!strcmp(cmd,"r32")){uint32_t a=strtoul(a1,0,0); printf("%08x = %08x\n",a,core->rawRead32(core,a,-1));}
    else if(!strcmp(cmd,"dump")){uint32_t a=strtoul(a1,0,0),l=strtoul(a2,0,0); FILE*f=fopen(a3,"wb"); for(uint32_t i=0;i<l;i++)fputc(core->rawRead8(core,a+i,-1),f); fclose(f);}
    else if(!strcmp(cmd,"echo")) printf("%s",line+5);
    else if(!strcmp(cmd,"w8")){uint32_t a=strtoul(a1,0,0),v=strtoul(a2,0,0); core->rawWrite8(core,a,-1,v);}
    else if(!strcmp(cmd,"w16")){uint32_t a=strtoul(a1,0,0),v=strtoul(a2,0,0); core->rawWrite16(core,a,-1,v);}
    else if(!strcmp(cmd,"w32")){uint32_t a=strtoul(a1,0,0),v=strtoul(a2,0,0); core->rawWrite32(core,a,-1,v);}
    else if(!strcmp(cmd,"writesav")){void* sd=NULL; size_t sz=core->savedataClone(core,&sd); FILE*f=fopen(a1,"wb"); fwrite(sd,1,sz,f); fclose(f); free(sd); printf("wrote %zu\n",sz);}
    else if(!strcmp(cmd,"loadsav")){FILE*f=fopen(a1,"rb"); if(!f){printf("nosav\n");continue;} fseek(f,0,SEEK_END); long sz=ftell(f); fseek(f,0,SEEK_SET); void* b=malloc(sz); fread(b,1,sz,f); fclose(f); core->savedataRestore(core,b,sz,true); free(b); core->reset(core);}
    else if(!strcmp(cmd,"reset")) core->reset(core);
    fflush(stdout);
  }
  core->deinit(core); return 0;
}

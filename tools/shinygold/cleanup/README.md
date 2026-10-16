# Unused-content cleanup

Run in this order (each takes the tree path; the list files are plain text):

1. `stub_maps.py <tree> <maps.txt>`: empties maps no warp, connection or live script reaches. The map slot and id
   stay, so saves keep loading on the right map. Map list made with `tools/shinygold/gold/treereach.py`.
2. `walled_events.py <tree> > list.txt`: objects/signs sealed inside walls and coord triggers on impassable
   tiles. Review, add other dead events (`<Map> obj|bg|coord <0-based index>`), then
   `remove_events.py <tree> list.txt`. Objects keep their local ids (explicit_local_id), so nothing that refers to
   the rest changes.
3. `prune_labels.py <tree>`: deletes script/text/movement blocks nothing reaches any more.
4. `prune_tilesets.py <tree>`: deletes tilesets no layout uses.

Repeat 2-3 until `walled_events.py` prints nothing; the build catches anything still referenced.

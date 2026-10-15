#!/bin/sh
# Regenerate all ShinyGold event-script outputs into a pokefirered worktree and verify them.
#   gen/run.sh WORKTREE [--fill-maps] [--no-verify]
# Outputs: WORKTREE/data/maps/*/scripts.inc|text.inc, data/scripts/*.inc, data/text/*.inc, data/event_scripts.s
#          /home/claude/work/scripts/{script_labels,natives,ram_refs,problems,coverage,...}.json
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
WT=$(cd "$1" && pwd); shift
JSON=/home/claude/work/scripts
FILL=0; VERIFY=1
for a in "$@"; do
  case "$a" in
    --fill-maps) FILL=1 ;;
    --no-verify) VERIFY=0 ;;
  esac
done
python3 "$HERE/sggen.py" "$WT" --json-dir "$JSON"
if [ "$FILL" = 1 ]; then python3 "$HERE/fill_map_scripts.py" "$WT" --labels "$JSON/script_labels.json"; fi
if [ "$VERIFY" = 1 ]; then
  python3 "$HERE/verify.py" "$WT" --json-dir "$JSON" --work "$JSON/verify"
  python3 "$HERE/coverage.py" --json-dir "$JSON" > /dev/null
  python3 "$HERE/summarize.py" --json-dir "$JSON" > /dev/null
fi

pio ci --project-conf platformio.ini --build-dir "out" --keep-build-dir "src" ".\examples\*"
cp test out/test -r
pio test -d "out"
rm -r "out"

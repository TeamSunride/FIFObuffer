pio ci --project-conf platformio.ini --build-dir "out" --keep-build-dir "src" "examples/*"
cp -R test out/test
pio test -d "out"
rm -R "out"

import strformat as sf

echo "What's your name? "
var name: string = readLine(stdin)
var fmt: string = "hi"
echo "Hi, ", name, "!"
echo sf.fmt"Yooo, {name} {fmt}!"
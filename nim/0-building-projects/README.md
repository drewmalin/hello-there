# Building nim Projects

## `nim compile`

### Debug/Test

Compile + Run

```
  nim compile --run greetings.nim
```

```
  nim c -r greetings.nim
```

Release
```
  nim compile -d:release greetings.nim
  ./greetings
```
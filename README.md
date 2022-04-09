# lua-io-isfile

[![test](https://github.com/mah0x211/lua-io-isfile/actions/workflows/test.yml/badge.svg)](https://github.com/mah0x211/lua-io-isfile/actions/workflows/test.yml)
[![codecov](https://codecov.io/gh/mah0x211/lua-io-isfile/branch/master/graph/badge.svg)](https://codecov.io/gh/mah0x211/lua-io-isfile)

determines whether the argument is the lua file handle or not.


## Installation

```
luarocks install io-isfile
```

---


## ok = isfile( f )

determines whether `f` is the lua file handle or not.

**Parameters**

- `f:any`: any value.

**Returns**

- `ok:boolean`: `true` if `f` is the lua file handle.

**e.g.**

```lua
local isfile = require('io.isfile')
local f = assert(io.open('./test.txt', 'w'))
local mt = getmetatable(f)
local fake = setmetatable({}, mt)

-- true
print(isfile(f)) 
-- false
print(isfile(fake))
print(isfile('foo'))
print(isfile(1))
```

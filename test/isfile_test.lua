local assert = require('assert')
local isfile = require('io.isfile')

local f = assert(io.tmpfile())
local mt = getmetatable(f)

-- test that returns true
assert.is_true(isfile(f))

-- test that returns false
local fake = setmetatable({}, mt)
for _, v in ipairs({
    fake,
    'foo',
    1,
    {},
    function()
    end,
}) do
    assert.is_false(isfile(v))
end
setmetatable(fake, nil)

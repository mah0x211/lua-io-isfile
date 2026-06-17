local testcase = require('testcase')
local assert = require('assert')
local isfile = require('io.isfile')

function testcase.isfile()
    -- test that returns true
    local f = assert(io.tmpfile())
    assert.is_true(isfile(f))
end

function testcase.not_isfile()
    local f = assert(io.tmpfile())
    local mt = getmetatable(f)

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
end

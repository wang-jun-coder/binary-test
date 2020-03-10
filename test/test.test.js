const assert = require('assert');
const hello = require('../index');

describe('binary-test', () => {

    it('hello', () => {
        const expect = 'Hello world';
        const res = hello.hello('world');
        assert.equal(expect, res);
    })

    it('add', () => {
        const expect = 3;
        const res = hello.add(1, 2);
        assert.equal(expect, res);
    })

    it('asyncAdd', async () => {
        const expect = 3;
        const res = await hello.asyncAdd(1, 2);
        assert.equal(expect, res);
    })
});
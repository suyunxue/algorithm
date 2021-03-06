/**
 * Initialize your data structure here.
 */
var RandomizedSet = function () {
    this.dict = {};
    this.list = [];
};

/**
 * Inserts a value to the set. Returns true if the set did not already contain the specified element. 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function (val) {
    if (this.dict[val] !== undefined) {
        return false;
    }

    this.dict[val] = this.list.length;
    this.list.push(val);
    return true;
};

/**
 * Removes a value from the set. Returns true if the set contained the specified element. 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function (val) {
    if (this.dict[val] === undefined) {
        return false;
    }


    var len = this.list.length;
    var lastElement = this.list[len - 1];

    var index = this.dict[val];
    var temp = this.list[index];
    this.list[index] = this.list[len - 1];
    this.list[len - 1] = temp;

    this.dict[lastElement] = index;
    this.list.pop();
    delete this.dict[val];

    return true;
};

/**
 * Get a random element from the set.
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function () {
    return this.list[Math.floor(Math.random() * this.list.length)];
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */

var res = new RandomizedSet();
res.insert(1);
res.remove(2);
res.insert(2);
res.getRandom();
res.remove(1);
res.insert(2);
console.log(res);
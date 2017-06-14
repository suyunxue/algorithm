/**
 * 动态规划
 *
 * 找出最小硬币数
 */
function MinCoinChange(coins) {
    var coins = coins;
    var cache = {};


    this.makeChange = function (amount) {
        var me = this;
        if (!amount) {
            return [];
        }

        if (cache[amount]) {
            return cache[amount];
        }

        var min = [];
        var newAmount;
        var newMin;
        for (var i = 0; i < coins.length; i++) {
            var coin = coins[i];
            newAmount = amount - coin;

            if (newAmount >= 0) {
                newMin = me.makeChange(newAmount);

            if (newAmount >= 0 &&
                (newMin.length < min.length - 1 || !min.length
                ) &&
                (newMin.length || !newAmount)
                ) {
                min = [coin].concat(newMin);
                console.log('new min ' + min + ' for ' + amount);
            }
        }


        return (cache[amount] = min);


    }
}

var minCoinChange = new MinCoinChange([1, 5, 10, 25]);
console.log(minCoinChange.makeChange(36));
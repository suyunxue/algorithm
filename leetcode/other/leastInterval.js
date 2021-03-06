/**
 * @param {character[]} tasks
 * @param {number} n
 * @return {number}
 */
var leastInterval = function(tasks, n) {
    const freq = {};
    for (let i = 0; i < tasks.length; i++) {
        freq[tasks[i]] = freq[tasks[i]] ? freq[tasks[i]] + 1 : 1;
    }

    const m = Object.keys(freq).length;
    const nextValid = new Array(m).fill(1);
    const rest = Object.values(freq);

    let time = 0;
    for (let i = 0; i < tasks.length; i++) {
        time++;
        let minNextValid = Number.MAX_VALUE;
        for (let j = 0; j < m; j++) {
            if (rest[j] > 0) {
                minNextValid = Math.min(nextValid[j], minNextValid);
            }
        }
        time = Math.max(time, minNextValid);
        let best = -1;
        for (let j = 0; j < m; j++) {
            if (rest[j] && nextValid[j] <= time) {
                if (best === -1 || rest[j] > rest[best]) {
                    best = j;
                }
            }
        }

        nextValid[best] = time + n + 1;
        rest[best]--;
    }

    return time;
};

let tasks = ["A","A","A","B","B","B"];
let res = leastInterval(tasks, 2);
console.log(res);
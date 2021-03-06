//函数原型： $.extend(obj, objA, objB);

function deepExtend(out) {

    //生成一个返回值
    //深扩展
    //遍历每个对象的所有属性，如果没有则添加，如果有覆盖
    //遍历的时候如果每个对象的属性是对象，那么就是递归进行复制

    out = out || {};

    for(var i = 1; i < arguments.length; i++) {

        var obj = arguments[i];

        if(!obj){
            continue;
        }

        for (var key in obj){
            if(obj.hasOwnProperty(key)){

                //如果一个属性的值是一个对象的话就继续递归复制

                if(typeof obj[key] === 'object') {
                    out[key] = deepExtend(out[key], obj[key]);
                }else {
                    out[key] = obj[key];
                }
            }

            out[key] = obj[key];
        }
    }

    return out;

}


deepExtend({}, objA, objB);


var extend = function (out) {

    var out = out || {};

    for (var i = 1; i < arguments.length; i++) {
        var obj = arguments[i];

        if(!obj){
            continue;
        }

        for(var key in obj) {
            if(obj.hasOwnProperty(key)) {
                out[key] = obj[key];
            }
        }
    }

    return out;
}

//把棋盘定为一个坐标，马可以到达页面中的任何地方，有一个数学公式
//设马的坐标为（x, y）马跳一次是（a, b）

function horse(p, q) {
	
	//假设p和q都是一个长度为2的数组
	var x = p[0];
	var y = p[1];
	var tarX = q[0];
	var tarY = q[1];
	
	//马每次跳的坐标是以他为中心周围的八个坐标，分别为
	var x = [x-2, y+1,
			 x-1, y+2,
			 x+1, y+2,
			 x+2, y+1,
			 x+2, y-1, 
			 x+1, y-2, 
			 x-1, y-2, 
			 x-2, y-1];

	

}
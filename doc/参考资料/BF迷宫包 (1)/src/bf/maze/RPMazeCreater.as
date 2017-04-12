package bf.maze{
	//随机普里姆法迷宫生成器
	//随机普里姆法属于广度优先搜索，生成的迷宫岔路较多，但相对都不深
	public class RPMazeCreater{
		//随机数种子
		private const MAXRATIO:Number=1/(uint.MAX_VALUE+1);
		private var _seed:uint;
		
		//迷宫参数
		private var _haveBorder:Boolean;
		private var _block:Object;
		private var _noBlock:Object;
		
		//存邻墙的列表
		private var blockPos:Array=new Array();
		
		//迷宫数组
		private var _mazeMap:Array;
		
		//构造函数，用于设置统一的迷宫参数
		//haveBorder外围是否带有一圈边框
		//block不可通行的表示法
		//noBlock可通行的表示法
		public function RPMazeCreater(haveBorder:Boolean=false,block:Object=true,noBlock:Object=false){
			_haveBorder=haveBorder;
			_block=block;
			_noBlock=noBlock;
		}
		
		//产生迷宫数组
		//mazeWidth迷宫的宽度
		//mazeHeight迷宫的高度
		//startX起点X，默认随机（不算边框和墙壁，从0起）
		//startY起点Y，默认随机（不算边框和墙壁，从0起）
		//seed迷宫种子，默认随机
		public function createMaze(mazeWidth:int,mazeHeight:int,startX:int=-1,startY:int=-1,seed:uint=0):Array{
			//设置随机种子，0就使用时间做种
			_seed=(seed || Math.floor(Math.random()*uint.MAX_VALUE)+1);
			
			//将返回的迷宫数组
			_mazeMap=new Array();
			
			//迷宫尺寸合法化
			if(mazeWidth<1)
			mazeWidth=1;
			if(mazeHeight<1)
			mazeHeight=1;
			
			//迷宫起点合法化
			if(startX<0 || startX>=mazeWidth)
			startX=Math.floor(rand()*mazeWidth);
			if(startY<0 || startY>=mazeHeight)
			startY=Math.floor(rand()*mazeHeight);
			
			//减去边框占的格子
			if(!_haveBorder){
				mazeWidth--;
				mazeHeight--;
			}
			
			//将迷宫的长宽换算成带墙的尺寸
			mazeWidth*=2;
			mazeHeight*=2;
			
			//将迷宫的起点换算成带墙的位置
			startX*=2;
			startY*=2;
			if(_haveBorder){
				startX++;
				startY++;
			}
			
			//产生出空白迷宫
			for(var x:int=0;x<=mazeWidth;x++){
				_mazeMap[x]=new Array();
				for(var y:int=0;y<=mazeHeight;y++){
					_mazeMap[x][y]=_block;
				}
			}
			
			//产生迷宫
			randomizedPrim(startX,startY,mazeWidth-1,mazeHeight-1);
			
			//返回生成的迷宫
			return _mazeMap;
		}
		
		//使用随机普里姆法产生迷宫数组
		//参数为迷宫（树）带墙的起点位置和长宽限制尺寸
		private function randomizedPrim(startX:int,startY:int,widthLimit:int,heightLimit:int){
			//随机墙的索引
			var blockIndex:int=0;
			
			//将起点作为目标格
			var targetX:int=startX;
			var targetY:int=startY;
			
			//标记起点
			_mazeMap[targetX][targetY]=_noBlock;
			
			//记录邻墙
			if(targetY>1){
				blockPos.push(targetX);
				blockPos.push(targetY-1);
				blockPos.push(0);
			}
			if(targetX<widthLimit){
				blockPos.push(targetX+1);
				blockPos.push(targetY);
				blockPos.push(1);
			}
			if(targetY<heightLimit){
				blockPos.push(targetX);
				blockPos.push(targetY+1);
				blockPos.push(2);
			}
			if(targetX>1){
				blockPos.push(targetX-1);
				blockPos.push(targetY);
				blockPos.push(3);
			}

			while(blockPos.length){
				//随机选一面墙
				blockIndex=Math.floor(rand()*(blockPos.length/3))*3;
				
				//找出此墙对面的目标格
				switch(blockPos[blockIndex+2]){
					case 0:
						targetX=blockPos[blockIndex];
						targetY=blockPos[blockIndex+1]-1;
						break;
					case 1:
						targetX=blockPos[blockIndex]+1;
						targetY=blockPos[blockIndex+1];
						break;
					case 2:
						targetX=blockPos[blockIndex];
						targetY=blockPos[blockIndex+1]+1;
						break;
					case 3:
						targetX=blockPos[blockIndex]-1;
						targetY=blockPos[blockIndex+1];
						break;
				}
				
				//如果目标格尚未连通
				if(_mazeMap[targetX][targetY]==_block){
					//连通目标格
					_mazeMap[blockPos[blockIndex]][blockPos[blockIndex+1]]=_noBlock;
					_mazeMap[targetX][targetY]=_noBlock;
					
					//添加目标格的邻格
					if(targetY>1 && _mazeMap[targetX][targetY-1]==_block && _mazeMap[targetX][targetY-2]==_block){
						blockPos.push(targetX);
						blockPos.push(targetY-1);
						blockPos.push(0);
					}
					if(targetX<widthLimit && _mazeMap[targetX+1][targetY]==_block && _mazeMap[targetX+2][targetY]==_block){
						blockPos.push(targetX+1);
						blockPos.push(targetY);
						blockPos.push(1);
					}
					if(targetY<heightLimit && _mazeMap[targetX][targetY+1]==_block && _mazeMap[targetX][targetY+2]==_block){
						blockPos.push(targetX);
						blockPos.push(targetY+1);
						blockPos.push(2);
					}
					if(targetX>1 && _mazeMap[targetX-1][targetY]==_block && _mazeMap[targetX-2][targetY]==_block){
						blockPos.push(targetX-1);
						blockPos.push(targetY);
						blockPos.push(3);
					}
				}
				
				//移除此墙
				blockPos.splice(blockIndex,3);
			}
		}
		
		//产生随机数
		private function rand():Number{
			_seed^=(_seed<<21);
			_seed^=(_seed>>>35);
			_seed^=(_seed<<4);
			return _seed*MAXRATIO;
		}
	}
}
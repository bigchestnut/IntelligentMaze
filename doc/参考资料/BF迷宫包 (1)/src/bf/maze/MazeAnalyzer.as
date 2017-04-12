package bf.maze{
	//迷宫分析器
	//用于对迷宫进行数据分析
	public class MazeAnalyzer{
		//迷宫宽度
		private var _mazeWidth:int=0;
		//迷宫高度
		private var _mazeHeight:int=0;
		//迷宫面积
		private var _mazeArea:int=0;
		//迷宫通路面积
		private var _pathArea:int=0;
		//迷宫通路面积百分比
		private var _mazeDensity:Number=0;
		//迷宫死路数（可选）
		private var _deadEnd:int=0;
		//迷宫丁字路口数（可选）
		private var _crossing3:int=0;
		//迷宫十字路口数（可选）
		private var _crossing4:int=0;
		//迷宫路口（丁字+十字）总数（可选）
		private var _crossing:int=0;
		//迷宫边（连接节点的线段）总数（可选）
		private var _edge:int=0;
		//迷宫节点（路口+死路）总数（可选）
		private var _node:int=0;
		//迷宫岛数量（可选）
		private var _island:int=0;
		//岛数组（可选）
		private var _islandArray:Array=null;
		
		//为了只读的getter们
		public function get mazeWidth():int{return _mazeWidth;}
		public function get mazeHeight():int{return _mazeHeight;}
		public function get mazeArea():int{return _mazeArea;}
		public function get pathArea():int{return _pathArea;}
		public function get mazeDensity():Number{return _mazeDensity;}
		public function get deadEnd():int{return _deadEnd;}
		public function get crossing3():int{return _crossing3;}
		public function get crossing4():int{return _crossing4;}
		public function get crossing():int{return _crossing;}
		public function get edge():int{return _edge;}
		public function get node():int{return _node;}
		public function get island():int{return _island;}
		public function get islandArray():Array{return _islandArray;}
		
		//分析迷宫
		//sMazeMap源迷宫数组
		//sBlock源迷宫不可通行的表示法
		//sNoBlock源迷宫可通行的表示法
		//analyzeConnection是否分析连通情况
		//analyzeIsland是否分析岛（封闭区域），真则返回岛数组
		public function analyzeMaze(sMazeMap:Array,sBlock:Object,sNoBlock:Object,analyzeConnection:Boolean=false,analyzeIsland:Boolean=false){
			//迷宫基本数据
			_mazeWidth=sMazeMap.length;
			_mazeHeight=sMazeMap[0].length;
			_mazeArea=_mazeWidth*_mazeHeight;
			
			//迷宫连接情况初始化
			if(analyzeConnection){
				_deadEnd=0;
				_crossing3=0;
				_crossing4=0;
				_crossing=0;
				_edge=0;
				_node=0;
			}else{
				_deadEnd=-1;
				_crossing3=-1;
				_crossing4=-1;
				_crossing=-1;
				_edge=-1;
				_node=-1;
			}
			
			//迷宫岛情况初始化
			if(analyzeIsland){
				_islandArray=new Array(_mazeWidth);
				_island=0;
			}else{
				_islandArray=null;
				_island=-1;
			}
			
			//迷宫分析
			_pathArea=0;
			for(var sx:int=0;sx<_mazeWidth;sx++){
				if(analyzeIsland)
				_islandArray[sx]=new Array(_mazeHeight);
				for(var sy:int=0;sy<_mazeHeight;sy++){
					if(sMazeMap[sx][sy]==sNoBlock){
						//统计通路面积
						_pathArea++;
						if(analyzeConnection){
							//分析连通情况
							var connection:int=0;
							if(sy>0 && sMazeMap[sx][sy-1]==sNoBlock){
								connection=1;
							}
							if(sx<_mazeWidth-1 && sMazeMap[sx+1][sy]==sNoBlock){
								connection++;
							}
							if(sy<_mazeHeight-1 && sMazeMap[sx][sy+1]==sNoBlock){
								connection++;
							}
							if(sx>0 && sMazeMap[sx-1][sy]==sNoBlock){
								connection++;
							}
							if(connection==0 && analyzeIsland){
								_island++;
								_islandArray[sx][sy]=_island;
							}else if(connection==1){
								_deadEnd++;
							}else if(connection==3){
								_crossing3++;
								_edge+=3;
							}else if(connection==4){
								_crossing4++;
								_edge+=4;
							}
						}
					}else if(analyzeIsland){
						_islandArray[sx][sy]=0;
					}
				}
			}
			
			//迷宫通路面积百分比
			_mazeDensity=_pathArea/_mazeArea;
			
			//迷宫连接情况
			if(analyzeConnection){
				_crossing=_crossing3+_crossing4;
				_edge=(_edge+_deadEnd)/2;
				_node=_crossing+_deadEnd;
			}
			
			//生成岛数组
			if(analyzeIsland){
				for(sx=0;sx<_mazeWidth;sx++){
					for(sy=0;sy<_mazeHeight;sy++){
						if(_islandArray[sx][sy]==undefined){
							_island++;
							exploreIsland(sx,sy);
						}
					}
				}
			}
		}
		//递归用的探索函数
		private function exploreIsland(x:int,y:int){
			_islandArray[x][y]=_island;
			if(x>0 && _islandArray[x-1][y]==undefined){
				exploreIsland(x-1,y);
			}
			if(y>0 && _islandArray[x][y-1]==undefined){
				exploreIsland(x,y-1);
			}
			if(x<_mazeWidth-1 && _islandArray[x+1][y]==undefined){
				exploreIsland(x+1,y);
			}
			if(y<_mazeHeight-1 && _islandArray[x][y+1]==undefined){
				exploreIsland(x,y+1);
			}
		}
	}
}
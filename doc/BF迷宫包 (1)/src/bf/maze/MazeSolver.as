package bf.maze{
	//迷宫求解器
	//用于对迷宫求解
	public class MazeSolver{
		//A星寻路参数
		private var _straightCost:int;
		private var _diagonalCost:int;
		private var _autoAlgorithm:Boolean;
		private var _stepLimit:int;
		private var _reusePath:Boolean;
		
		//内存优化，开/闭列表，路径列表
		private var openList:Array=new Array();//开列表结构为：F估价和，G已消耗，H预消耗，节点X，节点Y，父节点X，父节点Y
		private var closeList:Array=new Array();//闭列表结构为：节点X，节点Y，父节点X，父节点Y
		private var pathList:Array=new Array();
		
		//速度优化，节点访问情况列表，true在闭列表，false在开列表，undefined不在任何表
		private var nodeList:Array=new Array();
		
		//构造函数，用于设置A星寻路参数
		//straightCost直线花费
		//diagonalCost斜线花费
		//autoAlgorithm自动选择算法，为假的话，会始终使用最快的估价，否则在允许走斜线时会选用略慢的算法以提升路径质量
		//stepLimit寻路步数限制，到此步数即停止寻路
		//reusePath是否重复使用路径数组，有助于节省内存，但无法产生副本
		public function MazeSolver(straightCost:int=10,diagonalCost:int=14,autoAlgorithm:Boolean=true,stepLimit:int=0,reusePath:Boolean=false){
			_straightCost=straightCost;
			_diagonalCost=diagonalCost;
			_autoAlgorithm=autoAlgorithm;
			_stepLimit=stepLimit;
			_reusePath=reusePath;
		}
		
		//简单寻路
		//sMazeMap源迷宫数组
		//sBlock源迷宫不可通行的表示法
		//startX起点X坐标（序号0自开始）
		//startY起点Y坐标（序号0自开始）
		//finishX终点X坐标（序号0自开始）
		//finishY终点Y坐标（序号0自开始）
		//diagAble是否可以走斜线
		public function pathfinding(sMazeMap:Array,sBlock:Object,startX:int,startY:int,finishX:int,finishY:int,diagAble:Boolean=true):Array{
			//源迷宫的尺寸
			var sMazeWidth:int=sMazeMap.length;
			var sMazeHeight:int=sMazeMap[0].length;
			
			//排除不必要的寻路
			if(startX<0 || finishX<0 || startY<0 || finishY<0 || startX>=sMazeWidth || finishX>=sMazeWidth || startY>=sMazeHeight || finishY>=sMazeHeight || sMazeMap[finishX][finishY]==sBlock)
			return null;
			else if(startX==finishX && startY==finishY)
			return new Array(startX,startY);
			
			//要使用的估价函数
			var hFunction:Function=((_autoAlgorithm && diagAble)?diagonal:manhattan);
			
			//清空列表
			openList.splice(0);
			closeList.splice(0);
			nodeList.splice(0);
			
			//将开始节点放入开列表
			openList.splice(0,0,0,0,0,startX,startY,-1,-1);
			
			//A星寻路
			var currentNodeG:int=0;
			var currentNodeX:int=0;
			var currentNodeY:int=0;
			var G:int=0;
			var H:int=0;
			Astar:while(true){
				//找出开列表F最小的节点
				currentNodeG=openList[1];
				currentNodeX=openList[3];
				currentNodeY=openList[4];
				
				//将该节点移入封闭列表
				closeList.push(currentNodeX);
				closeList.push(currentNodeY);
				closeList.push(openList[5]);
				closeList.push(openList[6]);
				nodeList[currentNodeY*sMazeWidth+currentNodeX]=true;
				popNode();
				
				//检查当前节点的邻节点
				for(var dx:int=-1;dx<2;dx++){
					var adjNodeX:int=currentNodeX+dx;
					if(adjNodeX<0 || adjNodeX>=sMazeWidth)
					continue;
					
					for(var dy:int=-1;dy<2;dy++){
						if((diagAble || dx==0 || dy==0) && (dx!=0 || dy!=0)){
							var adjNodeY:int=currentNodeY+dy;
							if(adjNodeY<0 || adjNodeY>=sMazeHeight)
							continue;
							
							//检查是否抵达目的地
							if(adjNodeX==finishX && adjNodeY==finishY){
								break Astar;
							}
							
							//排除障碍和闭节点
							if(sMazeMap[adjNodeX][adjNodeY]==sBlock || nodeList[adjNodeY*sMazeWidth+adjNodeX])
							continue;
							
							//检查是否在开列表里
							G=currentNodeG+((dx==0 || dy==0)?_straightCost:_diagonalCost);
							if(nodeList[adjNodeY*sMazeWidth+adjNodeX]==undefined){
								//添加新节点
								H=hFunction(adjNodeX,adjNodeY,finishX,finishY);
								pushNode(G+H,G,H,adjNodeX,adjNodeY,currentNodeX,currentNodeY);
								nodeList[adjNodeY*sMazeWidth+adjNodeX]=false;
							}else{
								for(var i:int=openList.length-4;i>=0;i-=7){
									if(openList[i]==adjNodeX && openList[i+1]==adjNodeY){
										break;
									}
								}
								if(G<openList[i-2])
								//更新已有节点
								raiseNode(i-3,openList[i-1]+G,G,openList[i-1],adjNodeX,adjNodeY,currentNodeX,currentNodeY);
							}
						}
					}
				}
							
				//达到步数限制或者找不到路
				if((_stepLimit && openList.length>_stepLimit) || openList.length==0)
				return null;
			}
			
			//输出路径
			var path:Array;
			if(_reusePath){
				path=pathList;
				path.splice(0);
			}else{
				path=new Array();
			}
			path.unshift(finishY);
			path.unshift(finishX);
			path.unshift(currentNodeY);
			path.unshift(currentNodeX);
			i=closeList.length-4;
			while(i!=0){
				path.unshift(closeList[i+3]);
				path.unshift(closeList[i+2]);
				for(i-=4;i>=0;i-=4){
					if(closeList[i]==path[0] && closeList[i+1]==path[1])
					break;
				}
			}
			return path;
		}
		
		//加权寻路
		//sMazeMap源迷宫数组
		//sBlock源迷宫不可通行的表示法
		//startX起点X坐标（序号0自开始）
		//startY起点Y坐标（序号0自开始）
		//finishX终点X坐标（序号0自开始）
		//finishY终点Y坐标（序号0自开始）
		//diagAble是否可以走斜线
		public function weightedPathfinding(sMazeMap:Array,sBlock:Object,startX:int,startY:int,finishX:int,finishY:int,diagAble:Boolean=true):Array{
			//源迷宫的尺寸
			var sMazeWidth:int=sMazeMap.length;
			var sMazeHeight:int=sMazeMap[0].length;
			
			//排除不必要的寻路
			if(startX<0 || finishX<0 || startY<0 || finishY<0 || startX>=sMazeWidth || finishX>=sMazeWidth || startY>=sMazeHeight || finishY>=sMazeHeight || sMazeMap[finishX][finishY]==sBlock)
			return null;
			else if(startX==finishX && startY==finishY)
			return new Array(startX,startY);
			
			//要使用的估价函数
			var hFunction:Function=((_autoAlgorithm && diagAble)?diagonal:manhattan);
			
			//清空列表
			openList.splice(0);
			closeList.splice(0);
			nodeList.splice(0);
			
			//将开始节点放入开列表
			openList.splice(0,0,0,0,0,startX,startY,-1,-1);
			
			//A星寻路
			var currentNodeG:int=0;
			var currentNodeX:int=0;
			var currentNodeY:int=0;
			var G:int=0;
			var H:int=0;
			Astar:while(true){
				//找出开列表F最小的节点
				currentNodeG=openList[1];
				currentNodeX=openList[3];
				currentNodeY=openList[4];
				
				//将该节点移入封闭列表
				closeList.push(currentNodeX);
				closeList.push(currentNodeY);
				closeList.push(openList[5]);
				closeList.push(openList[6]);
				nodeList[currentNodeY*sMazeWidth+currentNodeX]=true;
				popNode();
				
				//检查当前节点的邻节点
				for(var dx:int=-1;dx<2;dx++){
					var adjNodeX:int=currentNodeX+dx;
					if(adjNodeX<0 || adjNodeX>=sMazeWidth)
					continue;
					
					for(var dy:int=-1;dy<2;dy++){
						if((diagAble || dx==0 || dy==0) && (dx!=0 || dy!=0)){
							var adjNodeY:int=currentNodeY+dy;
							if(adjNodeY<0 || adjNodeY>=sMazeHeight)
							continue;
							
							//检查是否抵达目的地
							if(adjNodeX==finishX && adjNodeY==finishY){
								break Astar;
							}
							
							//排除障碍和闭节点
							if(sMazeMap[adjNodeX][adjNodeY]==sBlock || nodeList[adjNodeY*sMazeWidth+adjNodeX])
							continue;
							
							//检查是否在开列表里
							G=currentNodeG+((dx==0 || dy==0)?_straightCost:_diagonalCost)+sMazeMap[adjNodeX][adjNodeY];
							if(nodeList[adjNodeY*sMazeWidth+adjNodeX]==undefined){
								//添加新节点
								H=hFunction(adjNodeX,adjNodeY,finishX,finishY);
								pushNode(G+H,G,H,adjNodeX,adjNodeY,currentNodeX,currentNodeY);
								nodeList[adjNodeY*sMazeWidth+adjNodeX]=false;
							}else{
								for(var i:int=openList.length-4;i>=0;i-=7){
									if(openList[i]==adjNodeX && openList[i+1]==adjNodeY){
										break;
									}
								}
								if(G<openList[i-2])
								//更新已有节点
								raiseNode(i-3,openList[i-1]+G,G,openList[i-1],adjNodeX,adjNodeY,currentNodeX,currentNodeY);
							}
						}
					}
				}
							
				//达到步数限制或者找不到路
				if((_stepLimit && openList.length>_stepLimit) || openList.length==0)
				return null;
			}
			
			//输出路径
			var path:Array;
			if(_reusePath){
				path=pathList;
				path.splice(0);
			}else{
				path=new Array();
			}
			path.unshift(finishY);
			path.unshift(finishX);
			path.unshift(currentNodeY);
			path.unshift(currentNodeX);
			i=closeList.length-4;
			while(i!=0){
				path.unshift(closeList[i+3]);
				path.unshift(closeList[i+2]);
				for(i-=4;i>=0;i-=4){
					if(closeList[i]==path[0] && closeList[i+1]==path[1])
					break;
				}
			}
			return path;
		}
		
		//manhattan估价算法，以直线距离为基准估价
		//作为优化，用?:代替了Math.abs与Math.min
		private function manhattan(tx:int,ty:int,fx:int,fy:int):int{
			return (((tx<fx)?(fx-tx):(tx-fx))+((ty<fy)?(fy-ty):(ty-fy)))*_straightCost;
		}
		
		//diagonal估价算法，以对角线和直线距离为基准
		//作为优化，用?:代替了Math.abs与Math.min
		private function diagonal(tx:int,ty:int,fx:int,fy:int):int{
			var dx:int=((tx<fx)?(fx-tx):(tx-fx));
          	var dy:int=((ty<fy)?(fy-ty):(ty-fy));
			var diag:int=((dx<dy)?dx:dy);
			return diag*_diagonalCost+_straightCost*(dx+dy-2*diag);
		}
		
		//=======二叉堆（开表）的操作=======
		
		//添加节点
		private function pushNode(F:int,G:int,H:int,x:int,y:int,px:int,py:int){
			//把这个元素和根节点比较并交换
			var tmp:int=0;
			for(var i:int=openList.length;i>0;i=tmp){
				tmp=((i/7-1)>>1)*7;
				if(F<openList[tmp]){
					openList[i]=openList[tmp];
					openList[i+1]=openList[tmp+1];
					openList[i+2]=openList[tmp+2];
					openList[i+3]=openList[tmp+3];
					openList[i+4]=openList[tmp+4];
					openList[i+5]=openList[tmp+5];
					openList[i+6]=openList[tmp+6]; 
				}else{
					break;
				} 
			} 
			openList[i]=F;
			openList[i+1]=G;
			openList[i+2]=H;
			openList[i+3]=x;
			openList[i+4]=y;
			openList[i+5]=px;
			openList[i+6]=py; 
		}
		
		//删除节点
		private function popNode(){
			//和左右子树中较小的比较并交换
			var tmp:int=7;
			var len:int=openList.length-7;
			for(var i:int=0;tmp<len;){
				if(tmp+7<len && openList[tmp+7]<openList[tmp])
				tmp+=7;
				
				if(openList[tmp]<openList[len]){
					openList[i]=openList[tmp];
					openList[i+1]=openList[tmp+1];
					openList[i+2]=openList[tmp+2];
					openList[i+3]=openList[tmp+3];
					openList[i+4]=openList[tmp+4];
					openList[i+5]=openList[tmp+5];
					openList[i+6]=openList[tmp+6]; 
				}else{
					break;
				}
				i=tmp;
				tmp=((i/7)*2+1)*7;
			} 
			openList[i]=openList[len];
			openList[i+1]=openList[len+1];
			openList[i+2]=openList[len+2];
			openList[i+3]=openList[len+3];
			openList[i+4]=openList[len+4];
			openList[i+5]=openList[len+5];
			openList[i+6]=openList[len+6];
			openList.length=len;
		}
		
		//修改节点
		private function raiseNode(index:int,F:int,G:int,H:int,x:int,y:int,px:int,py:int){
			//把这个元素和根节点比较并交换
			var tmp:int=0;
			for(var i:int=index;i>0;i=tmp){
				tmp=((i/7-1)>>1)*7;
				if(F<openList[tmp]){
					openList[i]=openList[tmp];
					openList[i+1]=openList[tmp+1];
					openList[i+2]=openList[tmp+2];
					openList[i+3]=openList[tmp+3];
					openList[i+4]=openList[tmp+4];
					openList[i+5]=openList[tmp+5];
					openList[i+6]=openList[tmp+6]; 
				}else{
					break;
				} 
			} 
			openList[i]=F;
			openList[i+1]=G;
			openList[i+2]=H;
			openList[i+3]=x;
			openList[i+4]=y;
			openList[i+5]=px;
			openList[i+6]=py; 
		}
	}
}
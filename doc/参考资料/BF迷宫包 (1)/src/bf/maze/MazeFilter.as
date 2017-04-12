package bf.maze{
	//迷宫滤镜
	//用于对原始迷宫进行特定修改
	public class MazeFilter{
		//随机数种子
		private const MAXRATIO:Number=1/(uint.MAX_VALUE+1);
		private var _seed:uint;
		
		//源迷宫参数
		private var _sBlock:Object;
		private var _sNoBlock:Object;
		
		//目标迷宫数组
		private var _dMazeMap:Array;
		
		//构造函数，用于设置源迷宫参数
		//sBlock源迷宫不可通行的表示法
		//sNoBlock源迷宫可通行的表示法
		public function MazeFilter(sBlock:Object=true,sNoBlock:Object=false){
			_sBlock=sBlock;
			_sNoBlock=sNoBlock;
		}
		
		//替换源迷宫标记
		//sMazeMap源迷宫数组
		//dBlock目标迷宫不可通行的表示法
		//dNoBlock目标迷宫可通行的表示法
		//createCopy是否创造新副本（深度拷贝）
		public function replaceFlag(sMazeMap:Array,dBlock:Object=true,dNoBlock:Object=false,createCopy:Boolean=false):Array{
			//源迷宫的尺寸
			var sMazeWidth:int=sMazeMap.length;
			var sMazeHeight:int=sMazeMap[0].length;
			
			//有需要就创建目标迷宫数组
			if(createCopy)
			_dMazeMap=new Array();
			
			//对源迷宫进行修改
			for(var sx:int=0;sx<sMazeWidth;sx++){
				if(createCopy)
				_dMazeMap[sx]=new Array();
				for(var sy:int=0;sy<sMazeHeight;sy++){
					if(createCopy){
						_dMazeMap[sx][sy]=(sMazeMap[sx][sy]==_sBlock?dBlock:dNoBlock);
					}else{
						sMazeMap[sx][sy]=(sMazeMap[sx][sy]==_sBlock?dBlock:dNoBlock);
					}
				}
			}
			
			//有需要就返回目标迷宫数组
			if(createCopy)
			return _dMazeMap;
			
			//返回修改后的源数组
			return sMazeMap;
		}
		
		//加权替换源迷宫标记，使用给定的数组元素，根据上下左右格子是否与当前格一样来替换迷宫标记
		//sMazeMap源迷宫数组
		//dBlock障碍数组（四周一致情况按上右下左顺序对应从低到高四位二进制数，该数组与此二进制数的十进制表示法相对应）
		//dNoBlock通路数组（四周一致情况按上右下左顺序对应从低到高四位二进制数，该数组与此二进制数的十进制表示法相对应）
		public function replaceWeightedFlag(sMazeMap:Array,dBlock:Array,dNoBlock:Array=null):Array{
			//合法性验证
			if((!dBlock && !dNoBlock) || (dBlock && dBlock.length!=16) || (dNoBlock && dNoBlock.length!=16))
			return null;
			
			//源迷宫的尺寸
			var sMazeWidth:int=sMazeMap.length;
			var sMazeHeight:int=sMazeMap[0].length;
			
			//创建目标迷宫数组
			_dMazeMap=new Array();
			
			//对目标迷宫进行填充
			var index:int=0;
			for(var sx:int=0;sx<sMazeWidth;sx++){
				_dMazeMap[sx]=new Array();
				for(var sy:int=0;sy<sMazeHeight;sy++){
					if((!dBlock && sMazeMap[sx][sy]==_sBlock)||(!dNoBlock && sMazeMap[sx][sy]==_sNoBlock)){
						_dMazeMap[sx][sy]=sMazeMap[sx][sy];
					}else{
						//检查连接情况
						index=0;
						if(sy>0 && sMazeMap[sx][sy-1]==sMazeMap[sx][sy]){
							index=1;
						}
						if(sx<sMazeWidth-1 && sMazeMap[sx+1][sy]==sMazeMap[sx][sy]){
							index+=2;
						}
						if(sy<sMazeHeight-1 && sMazeMap[sx][sy+1]==sMazeMap[sx][sy]){
							index+=4;
						}
						if(sx>0 && sMazeMap[sx-1][sy]==sMazeMap[sx][sy]){
							index+=8;
						}
						//用对应元素赋值
						if(sMazeMap[sx][sy]==_sBlock){
							_dMazeMap[sx][sy]=dBlock[index];
						}else{
							_dMazeMap[sx][sy]=dNoBlock[index];
						}
					}
				}
			}
			
			//返回目标迷宫数组
			return _dMazeMap;
		}
		
		//批量替换源迷宫标记
		//sMazeMap源迷宫数组
		//sFlagArray源迷宫需要替换的标记
		//dFlagArray目标迷宫对应的新标记
		//createCopy是否创造新副本（深度拷贝）
		public function replaceMultipleFlag(sMazeMap:Array,sFlagArray:Array,dFlagArray:Array,createCopy:Boolean=false):Array{
			//合法性验证
			if(sFlagArray.length!=dFlagArray.length)
			return null;
			
			//源迷宫的尺寸
			var sMazeWidth:int=sMazeMap.length;
			var sMazeHeight:int=sMazeMap[0].length;
			
			//有需要就创建目标迷宫数组
			if(createCopy)
			_dMazeMap=new Array();
			
			//对源迷宫进行修改
			var i:int=0;
			for(var sx:int=0;sx<sMazeWidth;sx++){
				if(createCopy)
				_dMazeMap[sx]=new Array();
				for(var sy:int=0;sy<sMazeHeight;sy++){
					i=sFlagArray.indexOf(sMazeMap[sx][sy]);
					if(i==-1){
						if(createCopy)
						_dMazeMap[sx][sy]=sMazeMap[sx][sy];
					}else{
						if(createCopy){
							_dMazeMap[sx][sy]=dFlagArray[i];
						}else{
							sMazeMap[sx][sy]=dFlagArray[i];
						}
					}
				}
			}
			
			//有需要就返回目标迷宫数组
			if(createCopy)
			return _dMazeMap;
			
			//返回修改后的源数组
			return sMazeMap;
		}
		
		//添加迷宫边框
		//sMazeMap源迷宫数组
		//createCopy是否创造新副本（深度拷贝）
		public function addBorder(sMazeMap:Array,createCopy:Boolean=false):Array{
			//源迷宫的尺寸
			var sMazeWidth:int=sMazeMap.length;
			var sMazeHeight:int=sMazeMap[0].length;
			
			//有需要就创建目标迷宫数组
			if(createCopy)
			_dMazeMap=new Array();
				
			//添加源迷宫的最外圈格
			for(var sx:int=0;sx<sMazeWidth;sx++){
				if(createCopy){
					_dMazeMap[sx]=new Array();
					for(var sy:int=0;sy<sMazeHeight;sy++){
						_dMazeMap[sx][sy]=sMazeMap[sx][sy];
					}
					_dMazeMap[sx].unshift(_sBlock);
					_dMazeMap[sx].push(_sBlock);
				}else{
					sMazeMap[sx].unshift(_sBlock);
					sMazeMap[sx].push(_sBlock);
				}
			}
			
			if(createCopy){
				_dMazeMap.unshift(new Array());
				_dMazeMap.push(new Array());
			}else{
				sMazeMap.unshift(new Array());
				sMazeMap.push(new Array());
			}
			
			var dx:int=sMazeWidth+1;
			var newHeight:int=sMazeHeight+2;
			for(var dy:int=0;dy<newHeight;dy++){
				if(createCopy){
					_dMazeMap[0][dy]=_sBlock;
					_dMazeMap[dx][dy]=_sBlock;
				}else{
					sMazeMap[0][dy]=_sBlock;
					sMazeMap[dx][dy]=_sBlock;
				}
			}
				
			//有需要就返回目标迷宫数组
			if(createCopy)
			return _dMazeMap;
			
			//返回修改后的源数组
			return sMazeMap;
		}
		
		//去除迷宫边框
		//sMazeMap源迷宫数组
		//createCopy是否创造新副本（深度拷贝）
		public function removeBorder(sMazeMap:Array,createCopy:Boolean=false):Array{
			//有需要就创建新迷宫数组
			if(createCopy){
				//源迷宫的尺寸
				var sMazeWidth:int=sMazeMap.length-1;
				var sMazeHeight:int=sMazeMap[0].length-1;
				
				//有需要就创建目标迷宫数组
				_dMazeMap=new Array();
				
				//移除源迷宫的最外圈格
				var dx:int=0;
				for(var sx:int=1;sx<sMazeWidth;sx++){
					_dMazeMap[sx]=new Array();
					for(var sy:int=1;sy<sMazeHeight;sy++){
						_dMazeMap[dx][sy]=sMazeMap[sx][sy];
					}
					dx++;
				}
				
				//有需要就返回目标迷宫数组
				return _dMazeMap;
			}
			
			//移除源迷宫的最外圈格
			sMazeMap.pop();
			sMazeMap.shift();
			var newWidth:int=sMazeMap.length;
			for(var x:int=0;x<newWidth;x++){
				sMazeMap[x].pop();
				sMazeMap[x].shift();
			}
			
			//返回修改后的源数组
			return sMazeMap;
		}
		
		//随机迷宫环路
		//sMazeMap源迷宫数组
		//loopRatio环路的比率（0-1，越大环路越多）
		//mustLoop结果是否必须是回路（为真时只考虑两侧是通路的墙，否则就随机拆除边框以外的墙）
		//seed随机数种子，默认随机
		//createCopy是否创造新副本（深度拷贝）
		public function randomizedLoop(sMazeMap:Array,loopRatio:Number=0.1,mustLoop:Boolean=true,seed:uint=0,createCopy:Boolean=false):Array{
			//设置随机种子，0就使用时间做种
			_seed=(seed || Math.floor(Math.random()*uint.MAX_VALUE)+1);
			
			//源迷宫的尺寸
			var sMazeWidth:int=sMazeMap.length-1;
			var sMazeHeight:int=sMazeMap[0].length-1;
			
			//有需要就创建目标迷宫数组
			if(createCopy)
			_dMazeMap=new Array();
			
			//产生出随机环路后的迷宫
			for(var sx:int=0;sx<=sMazeWidth;sx++){
				if(createCopy)
				_dMazeMap[sx]=new Array();
				for(var sy:int=0;sy<=sMazeHeight;sy++){
					if(sx>0 && sx<sMazeWidth && sy>0 && sy<sMazeHeight && sMazeMap[sx][sy]==_sBlock &&
						(!mustLoop || (sMazeMap[sx-1][sy]==_sNoBlock && sMazeMap[sx+1][sy]==_sNoBlock) || (sMazeMap[sx][sy-1]==_sNoBlock && sMazeMap[sx][sy+1]==_sNoBlock)) &&
																						  rand()<loopRatio){
						if(createCopy){
							_dMazeMap[sx][sy]=_sNoBlock;
						}else{
							sMazeMap[sx][sy]=_sNoBlock;
						}
					}else if(createCopy){
						_dMazeMap[sx][sy]=sMazeMap[sx][sy];
					}
				}
			}
			
			//有需要就返回目标迷宫数组
			if(createCopy)
			return _dMazeMap;
			
			//返回修改后的源数组
			return sMazeMap;
		}
		
		//随机迷宫边缘
		//sMazeMap源迷宫数组
		//pathRatio通路的比率（0-1，越大通路越多）
		//pathOnly是否只修改通路格
		//blurMode是否模糊边线，是的话会拆除墙壁格细分后的内侧，反之则只拆除外侧
		//seed随机数种子，默认随机
		public function randomizedEdge(sMazeMap:Array,pathRatio:Number=0.75,pathOnly:Boolean=false,blurMode:Boolean=false,seed:uint=0):Array{
			//设置随机种子，0就使用时间做种
			_seed=(seed || Math.floor(Math.random()*uint.MAX_VALUE)+1);
			
			//源迷宫的尺寸
			var sMazeWidth:int=sMazeMap.length;
			var sMazeHeight:int=sMazeMap[0].length;
			
			//将返回的目标迷宫数组
			_dMazeMap=new Array();
			
			//产生出随机边缘后的迷宫
			var mazeX:int=0;
			for(var sx:int=0;sx<sMazeWidth;sx++){
				for(var dx:int=-1;dx<2;dx++){
					_dMazeMap.push(new Array());
					mazeX=sx*3+1+dx;
					for(var sy:int=0;sy<sMazeHeight;sy++){
						for(var dy:int=-1;dy<2;dy++){
							if(pathOnly && sMazeMap[sx][sy]==_sBlock){
								_dMazeMap[mazeX].push(_sBlock);
							}else{
								if(sMazeMap[sx][sy]==_sNoBlock && (dx==0 || dy==0) && sx+dx!=-1 && sy+dy!=-1 && sx+dx!=sMazeWidth && sy+dy!=sMazeHeight && sMazeMap[sx+dx][sy+dy]==_sNoBlock){
									_dMazeMap[mazeX].push(_sNoBlock);
								}else if(sMazeMap[sx][sy]==_sBlock && ((dx==0 && dy==0) || (((blurMode && (dx+dy)%2==0) || (!blurMode && (dx==0 || dy==0))) && sx+dx!=-1 && sy+dy!=-1 && sx+dx!=sMazeWidth && sy+dy!=sMazeHeight && ((dy!=0 && sMazeMap[sx][sy+dy]==_sBlock) || (dx!=0 && sMazeMap[sx+dx][sy]==_sBlock))))){
									_dMazeMap[mazeX].push(_sBlock);
								}else{
									_dMazeMap[mazeX].push(rand()<pathRatio?_sNoBlock:_sBlock);
								}
							}
						}
					}
				}
			}
			
			//返回目标迷宫
			return _dMazeMap;
		}
		
		//均一随机填充，使用给定的数组元素，等概率随机填充迷宫的通路和障碍
		//sMazeMap源迷宫数组
		//pathArray通路数组（元素间概率相等）
		//blockArray障碍数组（元素间概率相等）
		//seed随机数种子，默认随机
		public function uniformFill(sMazeMap:Array,pathArray:Array=null,blockArray:Array=null,seed:uint=0):Array{
			//元素数量
			var pathNum:int=(pathArray?pathArray.length:0);
			var blockNum:int=(blockArray?blockArray.length:0);
			
			//合法性验证
			if(pathNum+blockNum==0)
			return null;
			
			//设置随机种子，0就使用时间做种
			_seed=(seed || Math.floor(Math.random()*uint.MAX_VALUE)+1);
			
			//源迷宫的尺寸
			var sMazeWidth:int=sMazeMap.length;
			var sMazeHeight:int=sMazeMap[0].length;
			
			//创建目标迷宫数组
			_dMazeMap=new Array();
			
			//对目标迷宫进行填充
			for(var sx:int=0;sx<sMazeWidth;sx++){
				_dMazeMap[sx]=new Array();
				for(var sy:int=0;sy<sMazeHeight;sy++){
					if(pathNum && sMazeMap[sx][sy]==_sNoBlock){
						_dMazeMap[sx][sy]=pathArray[Math.floor(rand()*pathNum)];
					}else if(blockNum && sMazeMap[sx][sy]==_sBlock){
						_dMazeMap[sx][sy]=blockArray[Math.floor(rand()*blockNum)];
					}else{
						_dMazeMap[sx][sy]=sMazeMap[sx][sy];
					}
				}
			}
			
			//返回目标迷宫数组
			return _dMazeMap;
		}
		
		//加权随机填充，使用给定的数组元素，按指定概率随机填充迷宫的通路和障碍
		//sMazeMap源迷宫数组
		//pathArray通路数组（按周围通路数量分为0-5六个数组）
		//pathWeight通路权值（元素概率为其概率/概率和）
		//blockArray障碍数组（按周围通路数量分为0-5六个数组）
		//blockWeight障碍权值（元素概率为其概率/概率和）
		//seed随机数种子，默认随机
		//内存优化，各组的权重和
		private var pathWeightMax:Array=new Array(6);
		private var blockWeightMax:Array=new Array(6);
		public function weightedFill(sMazeMap:Array,pathArray:Array=null,pathWeight:Array=null,blockArray:Array=null,blockWeight:Array=null,seed:uint=0):Array{
			//合法性验证
			if(!pathArray && !blockArray)
			return null;
			
			//提取各组的权重和
			try{
				var i:int=0;
				for(var g=0;g<6;g++){
					if(pathArray){
						if(pathArray[g].length==pathWeight[g].length){
							pathWeightMax[g]=0;
							for(i=pathArray[g].length-1;i>=0;i--){
								pathWeightMax[g]+=pathWeight[g][i];
							}
						}else{
							return null;
						}
					}
					if(blockArray){
						if(blockArray[g].length==blockWeight[g].length){
							blockWeightMax[g]=0;
							for(i=blockArray[g].length-1;i>=0;i--){
								blockWeightMax[g]+=blockWeight[g][i];
							}
						}else{
							return null;
						}
					}
				}
			}catch(e:Error){
				return null;
			}
			
			//设置随机种子，0就使用时间做种
			_seed=(seed || Math.floor(Math.random()*uint.MAX_VALUE)+1);
			
			//源迷宫的尺寸
			var sMazeWidth:int=sMazeMap.length;
			var sMazeHeight:int=sMazeMap[0].length;
			
			//创建目标迷宫数组
			_dMazeMap=new Array();
			
			//对目标迷宫进行填充
			var r:Number=0;
			for(var sx:int=0;sx<sMazeWidth;sx++){
				_dMazeMap[sx]=new Array();
				for(var sy:int=0;sy<sMazeHeight;sy++){
					if((!blockArray && sMazeMap[sx][sy]==_sBlock)||(!pathArray && sMazeMap[sx][sy]==_sNoBlock)){
						_dMazeMap[sx][sy]=sMazeMap[sx][sy];
					}else{
						//检查连通数
						g=0;
						if(sx>0 && sMazeMap[sx-1][sy]==_sNoBlock){
							g++;
						}
						if(sx<sMazeWidth-1 && sMazeMap[sx+1][sy]==_sNoBlock){
							g++;
						}
						if(sy>0 && sMazeMap[sx][sy-1]==_sNoBlock){
							g++;
						}
						if(sy<sMazeHeight-1 && sMazeMap[sx][sy+1]==_sNoBlock){
							g++;
						}
						if(g==4){
							if(sx>0 && sy>0 && sMazeMap[sx-1][sy-1]==_sNoBlock){
								g=5;
							}else if(sx<sMazeHeight-1 && sy>0 && sMazeMap[sx+1][sy-1]==_sNoBlock){
								g=5;
							}if(sx>0 && sy<sMazeHeight-1 && sMazeMap[sx-1][sy+1]==_sNoBlock){
								g=5;
							}if(sx<sMazeHeight-1 && sy<sMazeHeight-1 && sMazeMap[sx+1][sy+1]==_sNoBlock){
								g=5;
							}
						}
						//选出元素
						if(sMazeMap[sx][sy]==_sNoBlock){
							r=rand()*pathWeightMax[g];
							for(i=pathWeight[g].length-1;i>=0;i--){
								if(r<pathWeight[g][i]){
									break;
								}else{
									r-=pathWeight[g][i];
								}
							}
							_dMazeMap[sx].push(pathArray[g][i]);
						}else{
							r=rand()*blockWeightMax[g];
							for(i=blockWeight[g].length-1;i>=0;i--){
								if(r<blockWeight[g][i]){
									break;
								}else{
									r-=blockWeight[g][i];
								}
							}
							_dMazeMap[sx][sy]=blockArray[g][i];
						}
					}
				}
			}
			
			//返回目标迷宫数组
			return _dMazeMap;
		}
		
		//偏倚随机填充，使用给定的数组元素，按指定概率和优先级随机填充迷宫的通路和障碍
		//sMazeMap源迷宫数组
		//pathArray通路数组（按周围通路数量分为0-5六个数组，靠前的元素优先）
		//pathWeight通路概率（元素概率为其概率*之前元素未选中概率）
		//blockArray障碍数组（按周围通路数量分为0-5六个数组，靠前的元素优先）
		//blockWeight障碍概率（元素概率为其概率*之前元素未选中概率）
		//seed随机数种子，默认随机
		public function biasFill(sMazeMap:Array,pathArray:Array=null,pathWeight:Array=null,blockArray:Array=null,blockWeight:Array=null,seed:uint=0):Array{
			//合法性验证
			if(!pathArray && !blockArray)
			return null;
			
			try{
				for(var g=0;g<6;g++){
					if(pathArray){
						if(pathArray[g].length!=pathWeight[g].length){
							return null;
						}
					}
					if(blockArray){
						if(blockArray[g].length!=blockWeight[g].length){
							return null;
						}
					}
				}
			}catch(e:Error){
				return null;
			}
			
			//设置随机种子，0就使用时间做种
			_seed=(seed || Math.floor(Math.random()*uint.MAX_VALUE)+1);
			
			//源迷宫的尺寸
			var sMazeWidth:int=sMazeMap.length;
			var sMazeHeight:int=sMazeMap[0].length;
			
			//创建目标迷宫数组
			_dMazeMap=new Array();
			
			//对目标迷宫进行填充
			var i:int=0;
			var len:int=0;
			for(var sx:int=0;sx<sMazeWidth;sx++){
				_dMazeMap[sx]=new Array();
				for(var sy:int=0;sy<sMazeHeight;sy++){
					if((!blockArray && sMazeMap[sx][sy]==_sBlock)||(!pathArray && sMazeMap[sx][sy]==_sNoBlock)){
						_dMazeMap[sx][sy]=sMazeMap[sx][sy];
					}else{
						//检查连通数
						g=0;
						if(sx>0 && sMazeMap[sx-1][sy]==_sNoBlock){
							g++;
						}
						if(sx<sMazeWidth-1 && sMazeMap[sx+1][sy]==_sNoBlock){
							g++;
						}
						if(sy>0 && sMazeMap[sx][sy-1]==_sNoBlock){
							g++;
						}
						if(sy<sMazeHeight-1 && sMazeMap[sx][sy+1]==_sNoBlock){
							g++;
						}
						if(g==4){
							if(sx>0 && sy>0 && sMazeMap[sx-1][sy-1]==_sNoBlock){
								g=5;
							}else if(sx<sMazeHeight-1 && sy>0 && sMazeMap[sx+1][sy-1]==_sNoBlock){
								g=5;
							}if(sx>0 && sy<sMazeHeight-1 && sMazeMap[sx-1][sy+1]==_sNoBlock){
								g=5;
							}if(sx<sMazeHeight-1 && sy<sMazeHeight-1 && sMazeMap[sx+1][sy+1]==_sNoBlock){
								g=5;
							}
						}
						//选出元素
						if(sMazeMap[sx][sy]==_sNoBlock){
							len=pathWeight[g].length;
							for(i=0;i<len;i++){
								if(rand()<pathWeight[g][i]){
									break;
								}
							}
							if(i==len){
								_dMazeMap[sx][sy]=sMazeMap[sx][sy];
							}else{
								_dMazeMap[sx][sy]=pathArray[g][i];
							}
						}else{
							len=blockWeight[g].length;
							for(i=0;i<len;i++){
								if(rand()<blockWeight[g][i]){
									break;
								}
							}
							if(i==len){
								_dMazeMap[sx][sy]=sMazeMap[sx][sy];
							}else{
								_dMazeMap[sx][sy]=blockArray[g][i];
							}
						}
					}
				}
			}
			
			//返回目标迷宫数组
			return _dMazeMap;
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
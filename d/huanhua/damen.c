//damen.c

inherit ROOM;

void create()
{
        set("short", "浣花剑庐");
        set("long",@LONG
青山绿水间坐落着一座巍峨的建筑，这里就是名动天下的『浣花剑庐』。但
见这里红墙绿瓦，飞檐翘角，气派非凡，也不知凝聚了多少代浣花人的心血。自
从这里出了位大侠萧秋水以后，慕名而来的四方豪杰极多。在你的北面是一道朱
红漆大门，只是由于慕名而来的人太多，现在已经大门紧闭，不让闲人出入了。
LONG
      );
                 set("exits", ([
		  "east" : __DIR__"lu",
                "enter" : __DIR__"xiaoyuan",
        ]));
        	setup();
                set("valid_startroom", 1);
	        "/clone/board/huanhua_b"->foo();/*留言板的路径*/
        }


// Room: /d/shaolin/yidao.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
        set("short", "新手联盟");
	set("long", @LONG
这里就是新手联盟事务所了。一进门你就可以看到一张很大的圆桌
那是联盟成员们;开会的时候用的，桌上放着一本精美的留言本.房间两
壁都挂着一些草书;你从那些狂草中，勉强能认出几个字，好像是"光
明磊落”。事务所被树木所包围,这儿的一切都令你觉得安然陶醉,宁静
和祥…… 墙上一张纸上写着新手盟的宗旨(paper).
LONG );
	set("exits", ([
                "south" : "/d/taishan/yidao",
	]));
         set("objects",([
                 "/d/players/npc/xinshoumeng" : 1,
        ]));
        set("item_desc", ([
 "paper" : "组织新手联盟的唯一目的就是为了大家能更好的练功。
作为一个新手，再练功当中难免会碰到凭借自己一
个凭力量所难以完成的事情;凡是加入联盟的玩家的
唯一要求就是要有帮助他人的热心作为金庸的新玩家
我们会努力配合巫师，使金庸更加繁荣.
",
        ]));
        set("valid_startroom", 1);
        set("no_fight", "1");
          setup();
          "/clone/board/xinshoumeng"->foo();
	replace_program(ROOM);
}


// shufang.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是主人的书房，一张古意盎然的书案放在窗下，案上摆着几本翻开了的线
装书籍，后面有个书架，旁边还有张小床，看书累了，可以在这里躺一会。在桌上
有张字条(paper)，好象是写给后来人看的，四周的墙上挂着几幅字画，不乏名家
之作，正面的墙上居然是郑板桥的“兰竹图”，这里显得那么宁静，雅致。看来这
里的主人喜文胜于习武。 
LONG
	);set("item_desc", ([ /* sizeof() == 1 */
  	"paper" : " 浣花剑庐由小风(tree)写成于2002/03/28日，以此存鉴."
]));
        set("exits", ([ 
		"south" : __DIR__"dating", 		
                "enter" : __DIR__"mishi",
]));
        set("no_fight",1);
        set("no_steal",1);
        set("sleep_room",1);
        setup();
        replace_program(ROOM);	
}

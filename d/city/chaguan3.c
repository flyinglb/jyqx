// Room: /d/city/chaguan3.c

inherit CHATTING_ROOM;

void create()
{
        set("short", HIM"茶室"NOR);
        set("long", @LONG
这儿是茶馆里的茶室。这里布置得很典雅，茶香沁入心脾。四周的
茶客一边品茶，一边在观看一盘残局。还不时低声窃窃私语的议论着什
么，你不由得凑了过去，想听个究竟。
LONG
        );
//        set("resource/water", 1)
	set("exits", ([
                "south"  : __DIR__"chaguan",
	]));
        set("objects", ([
                __DIR__"obj/cch" : 1,
        ]));
        setup();
}

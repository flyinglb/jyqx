// Room: /d/city/chaguan1.c

inherit CHATTING_ROOM;

void create()
{
        set("short", HIM"茶室"NOR);
        set("long", @LONG
这儿是茶馆里的茶室。这里布置得很典雅，茶香沁入心脾。四周的
茶客一边品茶，一边高谈阔论。你仔细一听，似乎谈的是江湖上刚发生
的一件大事，你不由得凑了过去，想听个究竟。
LONG
        );
//        set("resource/water", 1)
	set("exits", ([
		"east"  : __DIR__"chaguan",
	]));
        setup();
        "/clone/board/chatroom1_b"->foo();
}


inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
���Ǹ����������ң�ǽ�ϵ��͵Ʒ����谵�Ļƹ⡣
LONG );
    set("exits", ([
        "up" : __DIR__"huayuan",
    ]));
    set("objects",([
        "/clone/book/zhemei_book1" : 1,
        "/clone/book/zhemei_book2" : 1,
        "/clone/book/liuyang_book1" : 1,
        "/clone/book/liuyang_book2" : 1,
        "/clone/book/qijianpu" : 1,
    ]));
    set("no_clean_up", 0);
    setup();
}

int valid_leave(object me, string dir)
{
    me=this_player();
   if ((dir=="up") &&
      (!present("zhangfa tu1", this_object())) ||
      (!present("zhangfa tu2", this_object())) ||
      (!present("shoufa tu1", this_object())) ||
      (!present("shoufa tu2", this_object())) ||
      (!present("pu", this_object())) )
          return notify_fail("����ؼ������������ܾ����أ�\n");

    return ::valid_leave(me, dir);
}

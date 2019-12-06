//cave.c
inherit ROOM;

void create()
{
  set("short","�Ҷ�");
  set("long",
        "�����Ǵ��Ҷ��������ڡ�����ɽ������ĵ��������¾�\n"
    "������������γɵġ��ϱ��������֡��������߾ͽ����ˡ�\n"
      );
  set("exits",([
      "north" : __DIR__"cave1",
      "southdown" : __DIR__"zhulin",
     ]));
 set("objects",([
      __DIR__"npc/mangshe" : 1,
      ]));
// set("no_clean_up", 0);
 set("outdoors","baituo");
 setup();
}

int valid_leave(object me, string dir)
{
   if (dir =="north" ) {
	if (objectp(present("mang she", environment(me))))
		return notify_fail("���ߵ�ס���ȥ·��\n");
		       }
   return ::valid_leave(me, dir);
}





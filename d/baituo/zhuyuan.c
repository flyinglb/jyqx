//zhuyuan.c
inherit ROOM;

void create()
{
  set("short","��԰");
  set("long",
      "������һ���ľ�����԰���߸ߵ͵͵Ĵ��������װ���\n"
  "�������¡��������Ǻ�Ժ���������и���Է���ϱ��ǻ�԰��\n"
     );
  set("exits",([
      "northeast" : __DIR__"tuyuan",
      "northwest" : __DIR__"houyuan",
      "south" : __DIR__"huayuan",
     ]));
  set("no_clean_up", 0);
  set("outdoors", "baituo");
  setup();
  replace_program(ROOM);
}


//fang.c
inherit ROOM;
void create()
{
  set("short","������");
  set("long",
      "�����ǰ���ɽ���ӵ��������������м������䣬�������ҡ�\n"
      "������������������գ����Բ��������˴����\n"
    );
  set("exits",([
      "west" : __DIR__"liangong",
      "1" : __DIR__"room1",
      "2" : __DIR__"room2",
      "3" : __DIR__"room3",
     
     ]));

 set("objects",([
     __DIR__"npc/trainer" : 1,
     ]));

// set("no_clean_up", 0);
 setup();
 replace_program(ROOM);

}
/*
int valid_leave(object who ,string dir)
{
 if((string)who->query("family/family_name")!="����ɽ��"
    &&(dir!="west"))
   return notify_fail("�����ֹ���˽��룡\n");
 return 1 ;
}
*/

//room: liangong.c

inherit ROOM;

void create()
{
  set("short","Ϸ���");
  set("long",@LONG
���������չ����������ĵط����м�������Ů������ר�����µ�����
���м����ֳ���,�ڻ������,���鶯�����紩������һ�㣬�㲻����
�����ۣ�����������ڵ��ϵ������Ͽ���������
LONG );
  set("exits",([
      "west" : __DIR__"changl4",
  ]));
  set("objects",([
          "/d/shaolin/npc/mu-ren" : 5
  ]));
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

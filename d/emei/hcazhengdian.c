//Room: hcazhengdian.c ����������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","����������");
      set("long",@LONG
�����Ƕ���ɽ�𶥻����ֵ���������ֹ�ģ��󣬵�����ש�̵أ��м�
�������������������������ǰ����һ��ľ���������������Թ�ߵ�ݡ�
�Դ����Ҹ���һ����ǽӴ���͵ĵط���������ͨ��һ����㳡��ֻ�ж�
�ҵ��Ӳ��ܹ�ȥ��
LONG);
      set("objects", ([
           CLASS_D("emei") + "/xin" : 1,
           __DIR__"npc/guest" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "out"    : __DIR__"huacangan",
          "east"   : __DIR__"hcaeast", 
          "west"   : __DIR__"hcawest", 
          "south"  : __DIR__"hcaguangchang", 
      ]));
//      set("no_clean_up", 0);
      setup();
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    me = this_player();
    myfam = (mapping)me->query("family");
    if ((!myfam || (myfam["family_name"] != "������")) && (dir == "south"))
      return notify_fail("�Ƕ��ҵ��ӣ�����ֹ���ɡ�\n");
    else  return 1;
}

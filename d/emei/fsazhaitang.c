//Room: fsanzhaitang.c ������ի��
//Date: Oct. 2 1997 by That
#include <room.h>
inherit ROOM;

void create()
{
      set("short","������ի��");
      set("long",@LONG
������Ƕ��Ҹ����ֵ�ի�á������ֱ����󣬵����ھ����Ӵ������ֵĵ��ӣ�
ի�õ�Ҳ��С��ֻ�����ڰ����˳����Ĳ����ͳ��ʣ���λСʦ̫������æµ�Ų���
��ի�����ϰ��˼��趹��������������Լ���Ѽ����ζ��ʳ��������һ����(door)��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "east"    : __DIR__"lingwenge",
          "northup" : __DIR__"fsaxiuxishi",
      ]));
      create_door("northup", "��", "southdown", DOOR_CLOSED);
      set("no_clean_up", 0);
      setup();
}

//Room: fsaxiuxishi.c ��������Ϣ��
//Date: Oct. 2 1997 by That
#include <room.h>
inherit ROOM;

void create()
{
      set("short","��������Ϣ��");
      set("long",@LONG
���Ǹ����ֽӴ�����Ů���ǵ���Ϣ�ң�����Ů���ӻ�ɽ֮ǰͨ���ڴ˽���
һ�ޣ��ñ���������ɽ�����ڰ���һ�ų�������ǽ���м���ľ����
LONG);
      set("exits",([ /* sizeof() == 1 */
          "southdown" : __DIR__"fsazhaitang",
      ]));
      create_door("southdown", "��", "northup", DOOR_CLOSED);
      set("sleep_room", 1);
      set("no_fight", 1);
      set("no_clean_up", 0);
      setup();
}

// Room: caolian2 ���������
// Date: Sep.30 1997
#include <room.h>

inherit ROOM;

void create()
{
      set("short", "���������");
      set("long", @LONG
��������˴󵶳�����ɳ�����ȵȣ����䵱�����ճ������ĵط���
LONG );

      set("exits", ([ /* sizeof() == 1 */
            "south"   : __DIR__"caolianfang",
      ]));
//      set("no_clean_up", 0);
      set("objects", ([
              "/d/shaolin/npc/mu-ren" : 4,  //�ĸ�ľ��
      ]));
      setup();
      replace_program(ROOM);
}

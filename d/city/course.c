// Room: bedroom.c
// Date: Sep.6 1997

#include <room.h>
inherit ROOM;

void create()
{
      set("short", "è��");
      set("long", @LONG
�������Ǻð���һ�䰮��С�ݣ��������͵Ĵ�����һ�־���
��С�������ϵ���֦�������ź���һȦȦ��ɢ������������һ��
�綯�󴲣���ͷС���ϲ����˾Űپ�ʮ�Ŷ������ĺ�õ�壬ӳ��
����Ĵ����󾵣��������Ҵ��硣
    ��������Сè�����������Ķ������硣
LONG );
      set("exits", ([ /* sizeof() == 1 */
          "east": __DIR__"jiaowai1",
      ]));
      set("valid_startroom","1");

      set("no_fight", 1);
//      set("no_clean_up", 0);
      set("sleep_room", 1);
      setup();
      create_door("east", "����С��", "west", DOOR_CLOSED);
}

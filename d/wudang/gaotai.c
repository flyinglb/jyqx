//Room: gaotai.c ���ҹ���̨
//Date: Sep 29 1997

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short","���ҹ���̨");
      set("long",@LONG
�����Ǿ������ҹ���̨����̨�����²࣬������Ԩ����ɲ⡣ɽ���
����������棬�پ����ϴ󿪡�
    �䵱���佣�����������佣�����������е��Ӱ������ϱ��е�ľ��
�𡢻�ˮ������λ���������Ե��Ӱ�Ǭ�����������롢�㡢���ޡ��Ұ�
���졢�ء�ˮ���𡢷硢�ס�ɽ�������С�
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/wuxing": 5,
           CLASS_D("wudang") +"/bagua": 8,
           CLASS_D("wudang") +"/yan": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown" : __DIR__"nanyangong",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

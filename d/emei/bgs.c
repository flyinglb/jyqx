//Room: bgs.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_ta();

void create()
{
      set("short","������");
      set("long",@LONG
�������Ƕ�üɽ�����Ժ֮һ��������ɽ���죬���յ���۵�߷��
�����ߣ���ģ��󡣵��ڷ������������������������ڷ����Ծ���������
����������һ��������(ta)������������Լ����ɴ�����¡�
LONG);
      set("outdoors", "emei");
      set("item_desc", ([
          "ta" : (: look_ta :),
      ]));
      set("objects", ([
               __DIR__+"npc/guest": 1,
               __DIR__+"npc/camel": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "east"     : __DIR__"bgsgate",
          "west"     : __DIR__"bgsxq",
          "enter"    : __DIR__"dxdian",
          "southwest": __DIR__"milin1",
      ]));
//      set("no_clean_up", 0);
      setup();
}
string look_ta()
{
        return
"    ����һ��ʮ������ͭ�����������������ף��������ѹ���С����ǧ�߰�\n"
"��֮�࣬�����С����Ͼ���ȫ��������֣���ұ��������񹤼��ɣ���������\n"
"����֮����\n";
}

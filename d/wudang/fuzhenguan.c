//Room: fuzhenguan.c ��������¥
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","��������¥");
      set("long",@LONG
��������¥�������أ������ʮ�������ʽ����ص����������
һ��֧�ţ��������ġ�һ��ʮ�������������︩�Ⱥɽ���������룬
Զ���𶥣�һ�����죬Ϊ�۾�ʤ�ء�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"     : __DIR__"taizipo",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

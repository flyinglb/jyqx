//Room: heilong1.c ������ջ��
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������ջ��");
      set("long",@LONG
������ջ���غ���������������һɽ�п������²������γ�һ��������ߣ�
���Ｘ���׵���Ͽ��������Ͽ��������ջ���ʹ���խ�İ���Ͽ��ת�۴�������
���ھ����ϡ�����ջ���ϣ�ֻ����խ��Σ�������������������ɽ����������
����ͷ���������϶���¿������ϡ�������쿪��ͼ�ġ�һ���졹��ջ����ͨ
ǧ���֣�����������
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south"      : __DIR__"heilong2",
          "northeast"  : __DIR__"qingyinge",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

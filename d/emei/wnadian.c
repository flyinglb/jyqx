//Room: wnadian.c ������ש��
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������ש��");
      set("long",@LONG
�����������ֵĹ�������ש�ש���ı�Ϊ�����Σ���Ϊ���Բ���Σ���
�����������������������ͭ����һ�𡣹�������ש���ı��·�����С���ʮ
�ĸ����ڸ�����������һ���ı��Ϸ����к�������������ͭ��С����������
����
LONG);
      set("objects", ([
           CLASS_D("emei") + "/kong" : 1,
           CLASS_D("emei") + "/wenfang" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "east"    : __DIR__"wnachanfang",
          "out"     : __DIR__"wannianan",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

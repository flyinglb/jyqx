//Room: jinding.c ��
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","��");
      set("long",@LONG
����Ƕ���ɽ��������ˡ��˷�������أ������Ʊ���������׳����
���������������ڤ���쿪���ʴ��ɻ����������Ͻ𶥣���Ұ��Ȼ���ʣ���
���£�����Ⱥ��ӿ�̵��䣬������˿���������Զ���������ѩɽ��ب��ʣ�
����ɽֱ���񷡣
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"wanxingan",
          "southwest"  : __DIR__"woyunan", 
          "south"      : __DIR__"huacangan",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

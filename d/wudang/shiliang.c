//Room: shiliang.c ʯ��
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ʯ��");
      set("long",@LONG
������ɽ���У���һ��ʯ����Ϫ�����������ǾŶɽ�������������֮ˮ��
�ڴ˽��㣬��ɫ���ѡ������������С�Ե꣬�������ˣ����СסЪЪ������
�����Ͼ��Ƕ��͵�ʮ�����ˡ�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northup"    : __DIR__"taizipo",
          "southup"    : __DIR__"shibapan",
          "east"       : __DIR__"shop",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

//Room: haohanpo.c �ú���
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","�ú���");
      set("long",@LONG
�˴�����ʮ����ɽ�ƶ��ͣ���Ϊ�ú��£�ɽ·����������ϸ�񣬴�ɫ���
�������ˣ���֪�����������������µ�ƣ�͡��¶���һ�������ۣ���չ������
�����ȥ�����������������ϲ��죬������ǰ������ȥʵ���ϻ�����ʮ�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"wdbl",
          "southdown": __DIR__"shanlu1",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

//Room: hcadadian.c �����ִ��۱���
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","�����ִ��۱���");
      set("long",@LONG
���Ƕ���ɽ�����ֵĴ��۱�����й���������������һȺ����Сʦ̫��
�ڵ����о��������е�С��ͨ����
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"hcaguangchang", 
          "south"      : __DIR__"hcahoudian", 
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

//Room: hcaeast2.c �����ֶ���
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","�����ֶ���");
      set("long",@LONG
�����Ƕ��һ����ֶ��ȡ���������ͨ��ի�ã�����ͨ���㳡��
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south" : __DIR__"hcazhaitang", 
          "north" : __DIR__"hcaeast1", 
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

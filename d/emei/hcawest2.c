//Room: hcawest2.c ����������
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","����������");
      set("long",@LONG
�����Ƕ��һ��������ȡ�������������������ͨ���㳡��
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south" : __DIR__"hcachanfang",
          "north" : __DIR__"hcawest1", 
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

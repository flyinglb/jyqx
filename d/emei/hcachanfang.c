//Room: hcachanfang.c ����������
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","����������");
      set("long",@LONG
������Ƕ��һ����ֵ�����������ɢ�ҵط���������ţ�ľ��ȣ��˴�
���Ǳ��ɵ��Ӵ�������֮������λ����ʦ̫���׼�Ů�����������붨��
��������������һ����ͨ����������Ϣ�ң����ߵ�����ͨ��㳡��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north" : __DIR__"hcawest2", 
          "south" : __DIR__"hcaxiuxishi", 
      ]));
      set("sleep_room", 1);
//      set("no_fight", 1);
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

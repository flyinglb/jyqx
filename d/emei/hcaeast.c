//Room: hcaeast.c �����ֲ��
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","�����ֲ��");
      set("long",@LONG
�����ǽ𶥻����ֶ����ǽӴ���ͼ������ĵط������ڰ��ż������ӣ�
����Χ���������ӡ�ǽ�����ż����ֻ���ǽ��һ����ܣ����ϰ������顣�м�
λ���������Ʒ����������ǽ�ϵ��ֻ����ļ��ϵľ��顣����������ʮ��
��Ĺ�������һλʦ̫�����йس��ҵ��¡�һ��ʮ�����Сʦ̫����æǰæ��
�д����ˡ�
LONG);
      set("objects", ([
           CLASS_D("emei") + "/he" : 1,
           CLASS_D("emei") + "/wenhui" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "west"   : __DIR__"hcazhengdian", 
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

//Room: chuwujian.c �����
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","�����");
      set("long",@LONG
������Ƕ��һ����ֵĴ���䣬���ܶ��Ǽ��ӡ�һ�����Ϸ����˸�����
�����г��������������޵ȣ�������Ŀ����һ�����Ϸ��˸��ַ��ߡ�����һ
�����ϰ������С���ӣ�ԭ����װ��ҩƷ��ҩ��һλʦ̫������������
��Ʒ����æµ��������ߡ���������и�С¥�ݡ��������ի���ˡ�
LONG);
      set("objects",([
           CLASS_D("emei") + "/feng" : 1,
           __DIR__"obj/fuchen" : 1,
           __DIR__"obj/zhujian" : 1,
           __DIR__"obj/jiudai" : 1,
           __DIR__"obj/yaodai" : 1,
//  ��(Ruanjian)
      ]));
      set("exits",([ /* sizeof() == 1 */
          "up"    : __DIR__"cangjingge", 
          "north" : __DIR__"hcazhaitang", 
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

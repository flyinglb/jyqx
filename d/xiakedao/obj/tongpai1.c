//tongpai1.c
//edit by noz

inherit ITEM;

void create()
{
  set_name( "����ͭ��",({"shan pai"}));
  set_weight(100);

  if( clonep() )
        set_default_object(__FILE__);

  set("unit", "��");
  set("long", "����һ����������İ�ͭƬ�ӣ�Լ�а��ƴ�С�������������һ��Ц�����Ͱ����顣\n");
  set("value", 100);

  setup();
}

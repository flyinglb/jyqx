// DOUJIANG.C ����
// By Marz 03/29/96

inherit ITEM;

void init();
void do_eat();

void create()
{
	set_name("����",({ "jiang"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵĶ���������\n");
		set("unit", "��");
		set("value", 500);
        set("remaining", 2);
        set("drink_supply", 30);
    }
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("����һ��������û����ɡ�\n");
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0);
    this_player()->add("water", (int)query("drink_supply"));
    destruct(this_object());
   return 1;
}

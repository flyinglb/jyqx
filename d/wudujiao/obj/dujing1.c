// dujing1.c

inherit ITEM;

void create()
{
	set_name("������ƪ", ({ "jing", "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������С�ᣬ�������������д���˸����ö��Ļ��������Ͷ�ҩ���䷽��\n�������(see)��һ����\n");
		set("value", 0);
		set("material", "silk");
		set("skill", ([
			"name":	"duji",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	50	// the maximum level you can learn
		]) );
	}
}
void init()
{
	add_action("do_read","see");
}
int do_read(string arg)
{
  if(arg=="jing"||arg=="book")
	return notify_fail("\n  �嶾����ҩ�䷽����Ч��\n
       ������+�߶���------>��ɫҩ��----->�߶�\n
       ������+��򼶾��---->��ɫҩ��----->��򼶾\n
       ���ǲ�+֩�붾��---->��ɫҩ��----->֩�붾\n
       �׶���+Ы�Ӷ���---->��ɫҩ��----->Ы�Ӷ�\n
       �ϳ���+��ܶ���---->��ɫҩ��----->��ܶ�\n
       ǧ����+���߶�Һ---->���ɵ�------->�Ի�ҩ\n
");
}

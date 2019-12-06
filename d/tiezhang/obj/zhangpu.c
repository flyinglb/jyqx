// zhangpu.c ��������
// by bren

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");      
}

void create()
{
        set_name("��������", ({ "tiezhang zhangpu", "zhangpu", "pu" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
			"��������\n"
			"����һ�������ҳ������飬ֽ�ʷ��ƣ���Ե��Ҳ�Ѳ�ȱ��ȫ�ˡ�\n");
                set("value", 50000);
                set("material", "paper");
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");

        }
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
//        object ob;
//        mapping skill;
        int level; 
	int neili_lost;

	if (!id(arg))
	return 0;

        if (where->query("pigging")){
                write("�㻹��ר�Ĺ���ɣ�\n");
                return 1;
        }
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }


        if (!id(arg)) {	
                write("��Ҫ��ʲô��\n");
                return 1;
        }
       
        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        switch(random(3)) {
          case 0:
        message("vision", me->name() + "����һ�����ڶ���\n", environment(me), me);
              break;
          case 1:
        message("vision", me->name() + "һ�߶��飬�������һ�߷��������Ĵ��졣\n", environment(me), me);
              break;
          case 2:
        message("vision", me->name() + "����ɫʱ��ʱ�࣬���粻����\n", environment(me), me);
              break;
        }
        if( (int)me->query("jing") < 15 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
	if (me->query("family/family_name") != "���ư�") {
		me->delete_skill("tiezhang-zhangfa");
                write("���ж���һ�ᣬ����������˵�Ķ������̫���ˡ�\n");
		return 1;
	}

        if ( me->query_skill("tiezhang-zhangfa", 1) > 100) neili_lost = 15;
	else
	if ( me->query_skill("tiezhang-zhangfa", 1) > 60) neili_lost = 10;
	else neili_lost = 5;


        if( (int)me->query("neili") < neili_lost) {
		write("�������������޷�������ô������书��\n");
                return 1;
        }

        level = me->query_skill("tiezhang-zhangfa", 1);
        if( (int)me->query("combat_exp") < (int)level*level*level/10 ) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }

       
        if( me->query_skill("tiezhang-zhangfa", 1) > 101){
                write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                return 1;
        }

        me->receive_damage("jing", 15);
	me->set("neili",(int)me->query("neili")-neili_lost);
        if( !me->query_skill("tiezhang-zhangfa", 1) ) {
                me->set_skill("tiezhang-zhangfa", 0);
/*
write("                   ���������ס��Ķ�ָ��\n"
"\n    ��ϲ�㿪ʼ��ϰ���ֵ�һ���򣭣�������а������\n"
"ע�����\n"
"һ����ϰ��а���������Թ������㲻���ñ��˷�������������ܣ������\n"
"    ��һ��������֮���Ķ����ҵ��б������ڳ�ʱ��Ҫʹ�ñ�а����ս����\n"
"    ��Ϊ�����Ķ���ʹ�ñ�а����ʱ�����һЩ����ľٶ���ʹ���˲�����\n"
"    �ɡ��мǲ�����ͽ��ݱ�����Ϊʦ�����ⱻ�˼����ļ��ܡ�\n\n"
"������а����������ǿ���ȿ����������ֿ�����Ų֮����\n\n"
"�������������䡷�������ˣ����ۣ���������ʰ��Ψһ�Ļ�ȡ��������ʹ��\n"
"    ��õ�������ȥ����Ѱ�ҡ�\n\n"
"�ģ���а��������ͨ����ʦ���Լ�������������ֻ��ͨ����ϰ���������ס�\n"
"    ����ߡ�\n\n"
"         ף�����ճ�Ϊ���ֵ�һ���֣��ư����£�\n");
*/
        }
        me->improve_skill("tiezhang-zhangfa", (int)me->query_skill("literate", 1)/3+1);
        write("���ж����������ס��������ĵá�\n");
        return 1;
}


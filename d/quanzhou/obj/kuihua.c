// kuihua.c ��������
// Jay 4/5/96

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
        add_action("do_join", "join");
}

void create()
{
        set_name("��������", ({ "kuihua baodian", "baodian", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��������ֵ�һ�ؼ����������䡷���ഫ��һλ����̫��������\n");
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
        object ob;
//        mapping skill;
        int pxlevel; 
	int neili_lost;

	if (!(arg=="kuihua baodian" || arg == "baodian" || arg == "book"))
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

/*        if(!arg || !objectp(ob = present(arg, me)) ){
                write("��Ҫ��ʲô��\n");
                return 1;
        }
*/
        if (!id(arg)) {	
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if ((string)me->query("gender") == "Ů��" ){
                write("�Թ�û��Ů�˿��Զ����������䡷�ġ�\n");
                return 1;
        }
        if ((string)me->query("gender") == "����" ) {
               write("���������䡷�ĵ�һҳд�ţ������񹦣������Թ���\n");
               return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        switch(random(3)) {
          case 0:
        message("vision", me->name() + "͵͵��������һ�����ڶ���\n", environment(me), me);
              break;
          case 1:
        message("vision", me->name() + "�߶����ɧ��Ū�ˣ�������ģ��Ů�ˡ�\n", environment(me), me);
              break;
          case 2:
        message("vision", me->name() + "�߶���߰�����Ť��Ťȥ��\n", environment(me), me);
              break;
        }
        if( (int)me->query("jing") < 15 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }

        if ( me->query_skill("pixie-jian", 1) > 84) neili_lost = 15;
	else
	if ( me->query_skill("pixie-jian", 1) > 74) neili_lost = 10;
	else neili_lost = 5;


        if( (int)me->query("neili") < neili_lost) {
		write("�������������޷�������ô������书��\n");
                return 1;
        }

        pxlevel = me->query_skill("pixie-jian", 1);
        if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }

        if( me->query_skill("pixie-jian", 1) > 9)
            if ((!objectp(ob = present("golden ring", me)) ) ||
               (!ob->query("equipped") )) {
                write("��û����ָ���е�������������ָ����\n");
                return 1;
        }
        if( me->query_skill("pixie-jian", 1) > 19)
            if ((!objectp(ob = present("flower shoes", me)) ) ||
               (!ob->query("equipped") )) {
                write("��û���廨Ь���е������������Ĳ�����\n");
                return 1;
        }
        if( me->query_skill("pixie-jian", 1) > 29)
            if ((!objectp(ob = present("xiuhua zhen", me)) ) ||
               (!ob->query("equipped") )) {
                write("��û���廨�룬�е��޷�����������������书��\n");
                return 1;
        }
        if( me->query_skill("pixie-jian", 1) > 39)
            if ((!objectp(ob = present("pink cloth", me)) ) ||
               (!ob->query("equipped") )) {
                write("��û��Ů�˵��������е�����������������\n");
                return 1;
        }
        if( me->query_skill("pixie-jian", 1) > 49)
            if ((!objectp(ob = present("golden necklace", me)) ) ||
               (!ob->query("equipped") )) {
                write("��û����������������������Ĺ���ȱ�����š�\n");
                return 1;
        }

        if( me->query_skill("pixie-jian", 1) > 59)
            if( me->query("rank_info/respect") != "����") {
		write("��������Ҫ��ʽ����(join)�������ܼ��������а������\n");
		write("����join����Ϊ������һλ̫�ࡣ�⽫��Ӱ�����ʦ�У�\n");
		write("���Ҵ�Ҷ��������Ϊ������\n");
		me->set_temp("pending/join",1);
                return 1;
        }


        if( me->query_skill("pixie-jian", 1) > 199){
                write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                return 1;
        }

        me->receive_damage("jing", 15);
	me->set("neili",(int)me->query("neili")-neili_lost);
        if( !me->query_skill("pixie-jian", 1) ) {
                me->set_skill("pixie-jian", 0);
write("                   ���������䡷�Ķ�ָ��\n"
"\n    ��ϲ�㿪ʼ��ϰ���ֵ�һ���򣭣�������а������\n"
"ע�����\n"
"һ����ϰ��а���������Թ������㲻���ñ��˷�������������ܣ������\n"
"    ��һ��������֮���Ķ����ҵ��б������ڳ�ʱ��Ҫʹ�ñ�а����ս����\n"
"    ��Ϊ�����Ķ���ʹ�ñ�а����ʱ�����һЩ����ľٶ���ʹ���˲�����\n"
"    �ɡ��мǲ�����ͽ��ݱ�����Ϊʦ�����ⱻ�˼����ļ��ܡ�\n\n"
"������а����������ǿ���ȿ����������ֿ�����Ų֮����\n\n"
"�������������䡷�������ˣ����ۣ���������ʰ��Ψһ�Ļ�ȡ��������ʹ��\n"
"    ��õ�������ȥ����Ѱ�ҡ�\n\n"
"�ģ���а��������ͨ����ʦ���Լ�������������ֻ��ͨ����ϰ���������䡷\n"
"    ����ߡ�\n\n"
"         ף�����ճ�Ϊ���ֵ�һ���֣��ư����£�\n");
        }
        me->improve_skill("pixie-jian", (int)me->query_skill("literate", 1)/3+1);
        write("���ж����������䡷�������ĵá�\n");
        return 1;
}

        
int do_join()
{
        if( this_player()->query("rank_info/respect") == "����") {
     		write("���Ѿ����붫���ˣ�����Ҫ���¼��롣\n");
		return 1;
	}

        if( !this_player()->query_temp("pending/join"))
	return 0;

	this_player()->set("rank_info/respect", "����");
	this_player()->set("rank_info/rude","����");
        write("��ϲ���Ϊ��͢����Ҫ�Ļ��ض�����һԱ��\n");
	this_player()->delete_temp("pending/join");
	return 1;
}
int query_autoload() { return 1; }


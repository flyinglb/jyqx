// roommaker.c
// for ESLib
// modify byp@jyqxz

#define RMK_VERSION "(v1.2)"

inherit ITEM;
inherit F_AUTOLOAD;

string *special_props = ({
	"short", "long" });

int save_room_file(string yn, string file, string str);

void create()
{
        set_name("����༭��" + RMK_VERSION, ({ "roommaker", "maker" }) );
	set_weight(100);
	set("unit", "��" );
	set("long", @LONG
����һ�����������١����췿��Ĺ��ߣ�����ʱ�䲻���������  lag ����ʦ
����������������򵥵ķ��䣬���������������Լ����򷿼��Ʒ�ʣ����
��Ҫ̫������������������ʹ�����¼���ָ�

mkroom <���䵵��>

    ���һ�����ա����䣬֮������� goto ����������� rset �趨�����
    ���������ԡ�

rset <��������> <��������>

    �趨��Ŀǰ���ڷ�������ԣ��� short��long �ȡ�

connect <����> <���䵵��>

    ����Ŀǰ���ڵķ�������һ�����ڵ���һ�����䡣

saveroom

    ����Ŀǰ���ڵķ���浵��
LONG
        );
}

int query_autoload() 
{ 
        if( wizardp(environment()) ) return 1; 
        else return 0;
}

void init()
{
	if( wizardp(environment()) ) {
		seteuid(getuid(environment()));
		add_action("do_mkroom", "mkroom");
		add_action("do_rset", "rset");
		add_action("do_connect", "connect");
		add_action("do_saveroom", "saveroom");
	} else {
	        set_name("����", ({ "cloth" }) );
                set_weight(3000);
                set("long", "����һ����ͨ���಼�£�������ͦ����ġ�");
                if( clonep() )
                        set_default_object(__FILE__);
                else {
                        set("unit", "��");
                        set("material", "cloth");
                        set("armor_prop/armor", 1);
                }
        }
}

int do_mkroom(string arg)
{
          string file, dir,note;

	if( !arg ) return notify_fail("ָ���ʽ��mkroom <���䵵��> [<����>]\n");
	if( sscanf(arg, "%s %s", file, dir)!=2 )
		file = arg;
	seteuid(geteuid(this_player()));
	file = resolve_path(this_player()->query("cwd"), file) + ".c";
	if( file_size(file)!=-1 )
		return notify_fail("���� " + file + " �Ѿ������ˡ�\n");
        
        note = "// This is a room made by roommaker.\n// "+ 
               file + " " + this_player()->query("id") + "@jyqxz " + ctime(time());
	
	if( !write_file(file, note + @ROOM_CODE

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", "�����ãã��һƬ����ʲôҲ��������\n");
	setup();
	replace_program(ROOM);
}
ROOM_CODE
	) ) return notify_fail("��û��д�뵵��(" + file +")��Ȩ����\n");
	message_vision("ֻ����$N�ķ���༭�����١���һ�����������������ֱ����һ�㡣\n", this_player());
	return 1;
}

int do_rset(string arg)
{
	string prop, str;
	mixed data;

	if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
		return notify_fail("ָ���ʽ��rset <��������> <��������>\n");

	if( sscanf(str, "%d", data)!=1 )
		data = str;

	environment(this_player())->set(prop, str);
	write("Ok.\n");
	return 1;
}

int do_connect(string arg)
{
	mapping exits;
	string dir, file;

	if( !arg || sscanf(arg, "%s %s", dir, file)!=2 )
		return notify_fail("ָ���ʽ��connect <����> <���䵵��>\n");
	file = resolve_path(this_player()->query("cwd"), file);
	exits = environment(this_player())->query("exits");
	if( mapp(exits) )
		exits[dir] = file;
	else
		environment(this_player())->set("exits", ([ dir: file ]) );
	write("Ok.\n");
	return 1;
}

int do_saveroom(string arg)
{
	object env;
	string str, *name, file;
	mapping prop;
	int i;

	env = environment(this_player());
	file = file_name(env) + ".c";
	str = "// Room: " + file + @ROOM_CODE


inherit ROOM;

void create()
{
ROOM_CODE
	;
	str += sprintf("\tset(\"short\", %O);\n", env->query("short") );
	str += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", env->query("long") );
	prop = env->query_entire_dbase();
	name = keys(prop);
	for(i=0; i<sizeof(name); i++) {
		if( member_array(name[i], special_props)!=-1 ) continue;
		str += sprintf("\tset(\"%s\", %O);\n", name[i], prop[name[i]] );
	}
	str += "\n\tsetup();\n\treplace_program(ROOM);\n}\n";

	// Replace current directory with __DIR__ macro to make relocatable code.
	i = strlen(file)-1;
	while( (i > 0) && (file[i]!='/')) i--;
	if( i>0 ) {
		write("ĿǰĿ¼��" + file[0..i] + " �� __DIR__ ȡ����\n");
		str = replace_string(str, "\"" + file[0..i], "__DIR__\"");
	}

	if( file_size(file)!=-1 ) {
		write("���� " + file + " �Ѵ��ڣ�Ҫɾ���ɵ���[y/n]");
		input_to("save_room_file", file, str);
		return 1;
	}

	return save_room_file("y", file, str);
}

int save_room_file(string yn, string file, string str)
{
	if( strlen(yn)<1 || yn[0]!='y' ) return 1;

	rm(file);
	write("�浵 " + file + "....");
	if( write_file(file, str) ) {
		write("Ok.\n");
		return 1;
	} else
		return notify_fail("��û��д���������(" + file + ")��Ȩ����\n");
}

void owner_is_killed() { destruct(this_object()); }

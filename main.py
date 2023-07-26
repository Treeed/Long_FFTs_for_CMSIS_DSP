import stringGenerators


start_power = 4
stop_power = 14

directory = "generatedFiles"

print(f"generating for {2**start_power} to {2**stop_power}")


lengths = [[power, 2**power] for power in range(start_power, stop_power+1)]


with open(f"{directory}/arm_common_tables_extra.c", "w") as table_file, open(f"{directory}/arm_common_tables_extra.h", "w") as header_file:
    header_file.write(stringGenerators.tables_header_start)
    table_file.write(stringGenerators.tables_file_start)

    # bit reversal table is only needed once for the highest power
    header_string, table_string = stringGenerators.bitrev_table(stop_power)
    table_file.write(table_string)
    header_file.write(header_string)

    header_string, table_string = stringGenerators.bitrevidx_table(lengths)
    table_file.write(table_string)
    header_file.write(header_string)

    header_string, table_string = stringGenerators.twiddle_complex_table(lengths)
    table_file.write(table_string)
    header_file.write(header_string)

    # we can't do a rfft for the lowest power, since a rfft always includes a cfft of length/2
    header_string, table_string = stringGenerators.twiddle_real_table(lengths[1:])
    table_file.write(table_string)
    header_file.write(header_string)

    header_file.write(stringGenerators.tables_header_end)
    table_file.write(stringGenerators.tables_file_end)


with open(f"{directory}/arm_rfft_fast_init_f32_extra.c", "w") as init_file:
    # we can't do a rfft for the lowest power, since a rfft always includes a cfft of length/2
    init_string = stringGenerators.rfft_init(lengths[1:])
    init_file.write(init_string)


with open(f"{directory}/arm_cfft_init_f32_extra.c", "w") as init_file:
    init_string = stringGenerators.cfft_init(lengths)
    init_file.write(init_string)


with open(f"{directory}/arm_const_structs_extra.c", "w") as struct_file, open(f"{directory}/arm_const_structs_extra.h", "w") as header_file:
    header_string, struct_string = stringGenerators.const_structs(lengths)
    struct_file.write(struct_string)
    header_file.write(header_string)

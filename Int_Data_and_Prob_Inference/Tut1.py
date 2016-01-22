import numpy as np



"""
/* question1 */
"""

print 'QUESTON1'
"""
/*creating the matrices*/
"""
 
prob_D_given_E = np.matrix([[0.4, 0.33, 0.29], [0.4, 0.33, 0.14], [0.2, 0.34, 0.14], [0, 0, 0.43]])

print('Probability matrix for P(D|E) is: ')
print prob_D_given_E

prob_S_given_E = np.matrix([[0, 0.33, 0.14], [0.6, 0, 0.14], [0.4, 0.34, 0], [0, 0.33, 0.14], [0, 0, 0.14], [0, 0, 0.14], [0, 0, 0.28]])

print('Probability matrix for P(S|E) is: ')
print prob_S_given_E

prob_F_given_C = np.matrix([[0, 0.3], [0.125,0], [0.125,0.14], [0.25, 0.14], [0.125, 0], [0.125, 0], [0, 0.14],  [0.125, 0.14], [0, 0.14], [0.125, 0.]])

print('Probability matrix for P(F|C) is: ')
print prob_F_given_C

prob_E_given_C = np.matrix([[0.5, 0.14], [0.25, 0.14], [0.25,0.72]])

print('Probability matrix for P(E|C) is: ')
print prob_E_given_C

"""
Given info of image-
instantiation of variables S,D and F
"""
s_vector = np.array([1.0,0.0,0.0,0.0,0.0,0.0,0.0])
d_vector = np.array([0.0,1.0,0.0,0.0])
f_vector = np.array([0.0,0.0,1,0.0])


def sum_over_columns(mat, vect, index):

    result = 0

    rows = mat.shape[0]
    cols = mat.shape[1]

    count = 0

    
    
    for k in range(len(vect)):        

        
        result += vect[k] * mat[k,index]
            

    return result

def simple_product(array1, array2):

    if(len(array1) != len(array2)):
        print 'not of same length!'

    array_result = {}
    
    for i in range(len(array1)):
          
        array_result[i] = array1[i] + array2[i]

    return array_result
        

def normalise_matrix(matrix):

    rows = matrix.shape[0]
    cols = matrix.shape[1]

    N = 0
    for i in range(rows):
        for j in range(cols):
            N += array[i,j]

    for j in range(rows):
        for j in range(cols):
            array[i,j] = array[i,j] / N


"""
Calculating the Sum of lamda messages coming from node S to E
"""
sum_lamda_e1_s = sum_over_columns(prob_S_given_E, s_vector, 0)
sum_lamda_e2_s = sum_over_columns(prob_S_given_E, s_vector, 1)
sum_lamda_e3_s = sum_over_columns(prob_S_given_E, s_vector, 2)

print 'seperate messages from S to E'
print sum_lamda_e1_s
print sum_lamda_e2_s
print sum_lamda_e3_s

sum_lamda_e1_d = sum_over_columns(prob_D_given_E, d_vector, 0)
sum_lamda_e2_d = sum_over_columns(prob_D_given_E, d_vector, 1)
sum_lamda_e3_d = sum_over_columns(prob_D_given_E, d_vector, 2)

print 'seperate messages from D to E'
print sum_lamda_e1_d
print sum_lamda_e2_d
print sum_lamda_e3_d

"""
Multiplying the separate messages to get lamda_E_to_C
"""

lamda_e1 = sum_lamda_e1_s * sum_lamda_e1_d
lamda_e2 = sum_lamda_e2_s * sum_lamda_e2_d
lamda_e3 = sum_lamda_e3_s * sum_lamda_e3_d

lamda_E_to_C = np.array([lamda_e1,lamda_e2,lamda_e3])

print 'lamda_E_to_C: '
print lamda_E_to_C


"""
Calculating the lamda message coming from F to C   


lamda_F_to_C = f_vector * prob_F_given_C
"""

"""
Calculating lamda C
"""

sum_lamda_c1_e = sum_over_columns(prob_E_given_C, lamda_E_to_C, 0)
sum_lamda_c2_e = sum_over_columns(prob_E_given_C, lamda_E_to_C, 1)

sum_lamda_c1_f = sum_over_columns(prob_F_given_C, f_vector, 0)
sum_lamda_c2_f = sum_over_columns(prob_F_given_C, f_vector, 1)

lamda_c1 = sum_lamda_c1_e * sum_lamda_c1_f
lamda_c2 = sum_lamda_c2_e * sum_lamda_c2_f


lamda_C = np.array([lamda_c1,lamda_c2])

print 'lamda C not normalised: '
print lamda_C


"""
normalising lamdaC
"""

sum = lamda_c1 + lamda_c2

lamdaC1 = lamda_c1 / sum
lamdaC2 = lamda_c2 / sum

lamdaC = np.array([lamdaC1, lamdaC2])

print 'lamda C normalised: '
print lamdaC


"""
add up all elements of the array



NF = 0
for i in range(lamda_F_to_C.shape[1]):
    N += lamda_F_to_C[i]

NE = 0
for i in range(lamda_E_to_C.shape[1]):
    N += lamda_E_to_C[i]

normalise each element of the array

for i in range(lamda_F_to_C.shape[1]):
    lamda_E_to_C[i] = lamda_F_to_C[i] / NF

for i in range(lamda_F_to_C.shape[1]):
    lamda_E_to_C[i] = lamda_F_to_C[i] / NE


"""

print 'QUESTION 4'


"""
Q4
"""
print 'QUESTION 4'

s_vector = np.array([0.8,0.2,0.0,0.0,0.0,0.0,0.0])
d_vector = np.array([0.3,0.4,0.3,0.0])
f_vector = np.array([1.,1.,1.,1.])



"""
Calculating the Sum of lamda messages coming from node S to E
"""
sum_lamda_e1_s = sum_over_columns(prob_S_given_E, s_vector, 0)
sum_lamda_e2_s = sum_over_columns(prob_S_given_E, s_vector, 1)
sum_lamda_e3_s = sum_over_columns(prob_S_given_E, s_vector, 2)

print 'seperate messages from S to E'
print sum_lamda_e1_s
print sum_lamda_e2_s
print sum_lamda_e3_s

sum_lamda_e1_d = sum_over_columns(prob_D_given_E, d_vector, 0)
sum_lamda_e2_d = sum_over_columns(prob_D_given_E, d_vector, 1)
sum_lamda_e3_d = sum_over_columns(prob_D_given_E, d_vector, 2)

print 'seperate messages from D to E'
print sum_lamda_e1_d
print sum_lamda_e2_d
print sum_lamda_e3_d

"""
Multiplying the separate messages to get lamda_E_to_C
"""

lamda_e1 = sum_lamda_e1_s * sum_lamda_e1_d
lamda_e2 = sum_lamda_e2_s * sum_lamda_e2_d
lamda_e3 = sum_lamda_e3_s * sum_lamda_e3_d

lamda_E_to_C = np.array([lamda_e1,lamda_e2,lamda_e3])

print 'lamda_E_to_C: '
print lamda_E_to_C


"""
Calculating lamda_C_from_E
"""

lamda_C_from_E = lamda_E_to_C * prob_E_given_C

print 'lamda C from E without F: '
print lamda_C_from_E


normalise_array(lamda_C_from_E)

print 'lamda C from E without F normalised: '
print lamda_C_from_E

"""
calculating the pi evidence coming down to F
"""
Prob_of_C = np.array([0.5, 0.5])



pi_message_to_F = simple_product(lamda_C_from_E,Prob_of_C) 



print 'pi message to F: '
print pi_message_to_F

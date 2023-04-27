$$\renewcommand{\ket}[1]{\left|{#1}\right\rangle}$$
$$\renewcommand{\bra}[1]{\left\langle{#1}\right|}$$
$$\renewcommand{\braket}[2]{\left\langle{#1}\middle|{#2}\right\rangle}$$
$$\newcommand{\ketbra}[2]{\left|{#1}\left\rangle \right\langle{#2}\right|}$$

## Vectors
1. Column vector $v$ and it's adjoint vector $v^{\dag}$ which is a row vector
 $$v       =\begin{bmatrix}v_1 \\ \vdots \\ v_n \end{bmatrix}  \quad \textsf{ and} \quad
   v^{\dag}={\begin{bmatrix}v_1 \\ \vdots \\ v_n \end{bmatrix}}^{\dag}
           = \begin{bmatrix}v_1^*\quad   \cdots \quad  v_n^* \end{bmatrix} \textsf{ where * denotes the complex conjugate}
  $$
2. Inner product of two column vectors $u$ and $v$ is denoted by $\left\langle u, v \right\rangle$
$$
\left\langle u, v \right\rangle = u^\dag v = \begin{bmatrix}u_1^* \quad \cdots \quad u_n^* \end{bmatrix} \begin{bmatrix}v_1 \\ \vdots \\ v_n \end{bmatrix}
=  u_1^*v_1 + \quad \cdots \quad u_n^*v_n = \sum_{i=1}^n{u^*_iv_i}
$$
3. Tensor product (also called matrix direct product, or Kronecker product).  This is distinguised from matrix multiplication. Two column vectors' tensor product. The tensor product is an operation on two matrices or vectors of arbitrary size.  The product of two matrices $M$ of size $m\times n $  and $N$ of size $p\times q$ is a larger matrix $P$ of size $mp \times nq$. The operator for tensor product is $\otimes$. Here are examples for row vector product and matrix tensor product.
$$
u \otimes v = \begin{bmatrix} a \\ b \end{bmatrix} \otimes \begin{bmatrix} c\\ d\\ e\end{bmatrix} 
            = \begin{bmatrix} a \begin{bmatrix} c \\ d \\ e   \end{bmatrix} \\ \\ b \begin{bmatrix} c \\ d \\e \end{bmatrix} \; \end{bmatrix}
            = \begin{bmatrix} ac \\ ad \\ ae \\ bc \\ bd \\ be \end{bmatrix}  \qquad \textsf{a } 2\times 3 = 6 \textsf{ row vector}
$$
        

$$
M \otimes N = \begin{bmatrix} a \quad b \\ c \quad  d  \end{bmatrix} \otimes \begin{bmatrix} e \quad f \\ g \quad h \end{bmatrix}
            = \begin{bmatrix} a \begin{bmatrix} e \quad f \\ g \quad h \end{bmatrix} \quad
                              b \begin{bmatrix} e \quad f \\ g \quad h \end{bmatrix} \\ \\
                              c \begin{bmatrix} e \quad f \\ g \quad h \end{bmatrix} \quad
                              d \begin{bmatrix} e \quad f \\ g \quad h \end{bmatrix}
              \; \end{bmatrix}
            = \begin{bmatrix} ae \quad af \quad ag \quad ah \\
                              be \quad bf \quad bg \quad bh \\
                              ce \quad cf \quad cg \quad ch \\
                              de \quad df \quad dg \quad dh 
              \; \end{bmatrix}   \qquad \textsf{a } 4\times 4 \textsf{ matrix}
$$
An $n$-fold repeated tensor product is denoted by $v^{\otimes n} $ or $M^{\otimes n}$, and here are some examples.
$$
\begin{bmatrix} 1 \\ 0 \end{bmatrix}^{\otimes 1} = \begin{bmatrix} 1 \\ 0 \end{bmatrix}, \qquad 
\begin{bmatrix} 1 \\ 0 \end{bmatrix}^{\otimes 2} = \begin{bmatrix} 1 \\ 0 \\ 0 \\ 0 \end{bmatrix}, \qquad 
\begin{bmatrix} 1 \\ -1 \end{bmatrix}^{\otimes 2} = \begin{bmatrix} 1 \\ -1 \\ -1 \\ 1 \end{bmatrix}, 
$$

$$
\begin{bmatrix} 0 \quad 1 \\ 1 \quad 0  \end{bmatrix}^{\otimes 1} = \begin{bmatrix} 0 \quad 1 \\ 1 \quad 0  \end{bmatrix}, \qquad
\begin{bmatrix} 0 \quad 1 \\ 1 \quad 0  \end{bmatrix}^{\otimes 2}
 = \begin{bmatrix}  
   0 \quad 0 \quad 0 \quad 1 \\
   0 \quad 0 \quad 1 \quad 0 \\
   0 \quad 1 \quad 0 \quad 0 \\
   1 \quad 0 \quad 0 \quad 0 
     \; \end{bmatrix}

$$

## A qubit and Dirac notation 

While a bit, or binary bit, can have a value either 0 or 1, a qubit can have a value that is either 0, 1, or a quantum superposition of 0 and 1.  The state of a single qubit can be described by a two-dimensional column vector of unit norm.  This vector, called the quantumn state vector, holds all the information needed to describe the one-qubit quantumn system. Any two-dimensional column vector of real or complex numbers with norm 1 represents a possible quantumn state held by a qubit. 

There are two types of vectors in Dirac notation: 1. the $bra$ vector(a row vector) denoted as $\bra{\cdot}$,   2. the $ket$ vector(a column vector), denoted as $\ket{\cdot}$. When putting together they form $braket$ or inner product, and is denoted as $\braket{\cdot}{\cdot}$. 

 Here are some exmaples of valid quantumn state vectors

$$
\ket{0}=\begin{bmatrix} \;  1 \; \\ \; 0 \; \end{bmatrix}, \quad
\ket{1}=\begin{bmatrix} \;  0 \; \\ \; 1 \; \end{bmatrix}, \quad
\ket{+}=\begin{bmatrix} \;  \frac{1}{\sqrt{2}} \; \\[8pt]  \; \frac{1}{\sqrt{2}} \; \end{bmatrix}
       = \frac{1}{\sqrt{2}} \left(\: \ket{0} + \ket{1} \:\right)
       , \quad
\ket{-}=\begin{bmatrix} \;  \frac{1}{\sqrt{2}} \; \\[8pt]   \; -\frac{1}{\sqrt{2}} \; \end{bmatrix}
       = \frac{1}{\sqrt{2}} \left(\: \ket{0} - \ket{1} \:\right)
       , \quad
\ket{0}= \frac{1}{\sqrt{2}} \left(\: \ket{+} + \ket{-} \:\right)
       , \quad
\ket{1}= \frac{1}{\sqrt{2}} \left(\: \ket{+} - \ket{-} \:\right)
$$

The bra-ket notation implies that $\braket{\psi}{\psi}$ is the inner product of vector $\psi$ with itself, which by definition 1. More generally, if $\psi$ and $\phi$ are quantum state vectors, then their inner product is $\braket{\phi}{\psi}$. This inner product implies that the probability of measuring the stat $\ket{\psi}$ to be $\ket{\phi}$ is  $|\braket{\psi}{\phi}|^2$.


As an example of Dirac notation, consider the braket $\braket{0}{1}$, 
$$
\braket{0}{1} =\begin{bmatrix} 1 \quad 0 \; \end{bmatrix} \begin {bmatrix} 0 \;  \\ 1 \; \end{bmatrix} = 0 = \braket{1}{0}, \; \textsf{ and also }\braket{0}{0}=\braket{1}{1} = 1
$$
This means that the two states are computational basis vector and they are also orthonormal. 

This orthonormal properties are very useful, such as if we have a state $\ket{\psi}=\frac{3}{5} \ket{0} + \frac{4}{5}\ket{1}$, then because $\braket{0}{1}=0$ the probability of measuring 1 is 
$$
|\braket{1}{\psi}|^2 = \left| \frac{3}{5}\braket{1}{1} +\frac{4}{5}\braket{1}{0} \right|^2 = \frac{9}{25}
$$

## Tensor product notation
  1. Tensor product of vectors     
     In quantum computing, the state vector described by two or more uncorrelated quantum registers is the tensor products of the two or more state vectors.  For any quantum state vector $\phi$ and $\psi$, the tensor product can be written as $\psi \otimes \phi = \ket{\psi} \otimes \ket{\phi} = \ket{\psi} \ket{\phi}$. For standard basis quantum state vector $ \ket{\psi} \ket{\phi} =\ket{\psi \phi}$. For example:    

     $$
         \ket{0}\otimes\ket{0}=\ket{0}\ket{0}=\ket{00}=\begin{bmatrix} \; 1 \; \\ \; 0 \; \end{bmatrix} \otimes \begin{bmatrix} \; 1 \; \\ \; 0 \; \end{bmatrix} = \begin{bmatrix} \; 1 \; \\ \; 0 \; \\ \; 0 \; \\ \; 0 \;\end{bmatrix}
     $$       
     and 
     $$
         \begin{bmatrix} 1 \\ 0 \end{bmatrix}^{\otimes n} =  \ket{0} \otimes \cdots \otimes \ket{0} = \ket{0}^{\otimes n}
     $$

     However for general vectors, the tensor product is:
     $$
         \textsf{let }  \; \ket{\psi}=\sum_{a \in \Sigma} {\alpha_a \ket{a}}  \textsf { and } \; \ket{\phi}=\sum_{b \in \Gamma} {\beta_b \ket{b}}  \textsf{ then } \\
         \ket{\psi} \otimes \ket{\phi} = \ket{\psi} \ket{\phi} = \sum_{(a, b) \in \Sigma \times \Gamma} {\alpha_a\beta_b \ket{ab}} 
     $$

     If $\ket{\phi_1}, \cdots, \ket{\phi_n}$ are vectors, then the tensor product $\ket{\psi}=\ket{\phi_1}\otimes \cdots \otimes \ket{\phi_n}$ is defined by the equation 
     $$
          \braket{a_1 \cdots a_n}{\psi} = \braket{a_1}{\phi_1} \cdots \braket{a_n}{\phi_n}
     $$
  2. Tensor product of matrices     
     $$
         M = \sum_{a,b\in \Sigma} \alpha_{ab}\ketbra{a}{b} \qquad \textsf{ and } \qquad N = \sum_{c,d\in \Gamma} \alpha_{cd}\ketbra{c}{d} \\[3pt]
         M\otimes N = \sum_{a,b\in \Sigma} \sum_{c,d\in \Gamma} \alpha_{ab}\alpha_{cd} \ketbra{ac}{bd} \qquad (\textsf{ for all } a, b \in \Sigma \textsf{ and } b, d \in \Sigma)
     $$     
     Equivalently, $M\otimes N$ is defined by this condition:
     $$
        \bra{ac} M \otimes N \ket{bd} = \bra{a} M \ket{b} \bra{c} N \ket{d}
     $$    
     Or, 
     $$
         \left( M \otimes N\right) \ket{\phi \otimes \psi} = M \ket{\phi} \otimes N \ket{\psi}  \qquad \textsf{ for every choice of vectors } \ket{\phi} \textsf{ and } \ket{\psi}
     $$
     If $M_1 \cdots M_n$ are matrices, then the tensor product $M_1 \otimes \cdots M_n$ is defined by the condition
     $$
        \bra{a_1 \cdot a_n} M_1 \otimes \cdots M_n \ket{b_1 \cdot b_n} = \bra{a_1}M_1 \ket{b_1} \cdots \bra{a_n} M_n \ket{b_n}
     $$

     Tensor product of matrices is $multiplicative$, i.e., 
     $$
        \left(M_1 \otimes \cdots M_n\right) \left(N_1 \otimes \cdots N_n\right) = \left(M_1 N_1\right)\otimes \cdots \otimes \left(M_n N_n\right)
     $$

## Linearity with Dirac notation
For two complex number $\alpha$ and $\beta$, we can write
$$
\ket{\psi}\otimes(\alpha\ket{\phi}+\beta\ket{\chi}) = \alpha \ket{\psi}\ket{\phi} + \beta\ket{\psi}\ket{\chi} 
$$

Bra vectors follow a similar convention to ket vectors. As $\bra{\psi}\bra{\phi} = \psi^{\dag} \otimes \phi^{\dag} = \left(\psi \otimes \phi\right)^{\dag}=\left(\ket{\psi\phi}\right)^{\dag}$. If a ket vector $\ket{\psi}=\alpha \ket{0}+\beta\ket{1}$, then the bra vector version of the vector is $\bra{\psi}=\ket{\psi}^{\dag}=\left(\bra{0}\alpha^* + \bra{1}\beta^*\right)$.
$$
\left|\braket{-}{\psi}\right|^2 = \left| \frac{1}{\sqrt{2}}\left(\bra{0}-\bra{1}\right) \left(\frac{3}{5}\ket{1}+\frac{4}{5}\ket{0} \right)\right|^2 =
\left|\frac{4}{5\sqrt{2}}-\frac{3}{5\sqrt{2}}\right|^2 = \frac{1}{50}
$$

## ketbra or outer product
The ketbra or outer product is denoted as $\ketbra{\psi}{\phi}=\psi\phi^{\dag}$ for quantum state vector $\psi$ and $\phi$. The out product is a matrix. The simplest and most common used is
$$
\ketbra{0}{0} = \begin{bmatrix} \; 1 \; \\ \; 0 \; \end{bmatrix} \begin{bmatrix} \; 1 \quad 0 \; \end{bmatrix} = 
\begin{bmatrix} 1 \quad 0 \\ 0 \quad 0  \end{bmatrix} \qquad
\ketbra{1}{1} = \begin{bmatrix} \; 0 \; \\ \; 1 \; \end{bmatrix} \begin{bmatrix} \; 0 \quad 1 \; \end{bmatrix} = 
\begin{bmatrix} 0 \quad 0 \\ 0 \quad 1  \end{bmatrix} \qquad
$$

# Quantum states

 If X and Y are qubits, the classical state set for the pair (X, Y) is 
 $$
    \left\{0, 1 \right\} \times \left\{0,1\right\} = \left\{0_X0_Y, 0_X1_Y, 1_X0_Y, 1_X1_Y\right\} = \left\{00, 01, 10, 11\right\}
 $$
 The following are exmaples of quantum state vectors of the pair(X,Y) expressed in following four ways (different styles and can be used at different scenario to make things clear)
 $$
    \begin{equation*}
    \begin{aligned}
    (a). \qquad &\frac{1}{2}\ket{0}\otimes\ket{0} + \frac{i}{2}\ket{0}\otimes\ket{1} - \frac{1}{2}\ket{1}\otimes\ket{0} -\frac{i}{2}\ket{1}\otimes\ket{1}, \qquad \frac{3}{5}\ket{0}\otimes\ket{0}, \qquad \ket{0}\otimes\ket{1} \\ 
    (b). \qquad &\frac{1}{2}\ket{0}_X\ket{0}_Y + \frac{i}{2}\ket{0}_X\ket{1}_Y - \frac{1}{2}\ket{1}_X\ket{0}_Y -\frac{i}{2}\ket{1}_X\ket{1}_Y, \qquad \frac{3}{5}\ket{0}_X\ket{0}_Y, \qquad \ket{0}_X\ket{1}_Y \\ 
    (c). \qquad &\frac{1}{2}\ket{0}\ket{0} + \frac{i}{2}\ket{0}\ket{1} - \frac{1}{2}\ket{1}\ket{0} -\frac{i}{2}\ket{1}\ket{1}, \qquad \frac{3}{5}\ket{0}\ket{0}, \qquad \ket{0}\ket{1} \\ 
    (d). \qquad &\frac{1}{2}\ket{00} + \frac{i}{2}\ket{01} - \frac{1}{2}\ket{10} -\frac{i}{2}\ket{11}, \qquad \frac{3}{5}\ket{00}, \qquad \ket{01}
    \end{aligned}
    \end{equation*}
 $$

Tensor products of quantum state vectors are also quantum state vectors. $\ket{\phi}$ is a quantum state vector of system $X$, and $\ket{\psi}$ is a quantum state vector of system $Y$, then $\ket{\phi}\otimes\ket{\psi}=\ket{\phi\psi}$ is a quantum state vector of the system $(X, Y)$.  States of this form are also called $product \; states$

More generally, if $\ket{\psi_1} \cdots \ket{\psi_n}$ are quantum state vectors of system $X_1 \cdots X_n$, then $\ket{\psi_1} \otimes \cdots \ket{\psi_n}$ is a quantum state vecter representing a product state of the compound system $(X_1 \cdots X_n)$. For example:
$$
\frac{1}{2}\ket{00} + \frac{i}{2}\ket{01} - \frac{1}{2}\ket{10} -\frac{i}{2}\ket{11} = \left(\frac{1}{\sqrt{2}} \ket{0} - \frac{1}{\sqrt{2}} \ket{1}\right)\otimes\left(\frac{1}{\sqrt{2}} \ket{0} + \frac{i}{\sqrt{2}} \ket{1}\right)
$$

Example of non-product state vector. $\frac{1}{\sqrt{2}}\ket{00} + \frac{1}{\sqrt{2}}\ket{11}$ not a product state vector.   
Suppose it were, then is it possible to write
$$
    \frac{1}{\sqrt{2}}\ket{00} + \frac{1}{\sqrt{2}}\ket{11} = \ket{\phi}\otimes \ket{\psi}
$$
the it follows 
$$
\braket{0}{\phi}\braket{1}{\psi} = \braket{01}{\phi \otimes \psi} = 0, \qquad \textsf{ implying that } \qquad \braket{0}{\phi} \textsf{ or } \braket{1}{\psi} = 0 \textsf { (or both) }
$$
These contradicts these equalities:
$$
  \braket{0}{\phi}\braket{0}{\psi}=\braket{00}{\phi \otimes \psi} = \frac{1}{\sqrt{2}} \qquad \textsf{ and } \qquad \braket{1}{\phi}\braket{1}{\psi}=\braket{11}{\phi \otimes \psi} = \frac{1}{\sqrt{2}}
$$

# Measurement of quantum states
  1. Measuring compound systems
   If $\ket{\psi}$ a quantum state of a system $\left(X_1, \cdots X_n\right)$, and every one of the systems is measured, then each n-tuple $\left(a_1, \cdots, a_n \right)\in \sum_1 \times \cdots \times \sum_n$ (or string $a_1 \cdots a_n$) is obtained with probabilit of $\left|\braket{a_1 \cdots a_2}{\psi} \right|$. For a quantum state of $(X, Y)$, i.e. $\ket{\psi}=\sum_{(a,b)\in \Sigma \times \Gamma}{\alpha_{ab}\ket{ab}}$, if both $X$ and $Y$ are meausred, then each outcome $(a,b)\in \Sigma \times \Gamma$ appears with probability of $\left|\braket{ab}{\psi}\right|^2 = \left|\alpha_{ab}\right|^2$
   For example, if the pair $(X, Y)$ is in quantum state $\frac{3}{5}\ket{0\; \spadesuit}+\frac{4i}{5}\ket{1\; \clubsuit}$. Then measuring both systems yields the outcome of $(0\;, \spadesuit)$ with probability 9/25 and the outcome $(0\;, \clubsuit)$ with probability of 16/25
  2. Meausing subsystmes of a compound system     
     For a quantum states of  $(X, Y)$
     $$
        \ket{\psi}=\sum_{(a,b)\in \Sigma \times \Gamma}{\alpha_{ab}\ket{ab}} \quad  => \quad\ket{\psi}=\sum_{a\in \Sigma }{\ket{a}} \otimes {\ket{\phi_a}} \; \textsf{ where } \; \ket{\phi_a} = \sum_{b \in \Gamma} \alpha_{ab}\ket{b} \; \textsf{ for each } \; a \in \Sigma \\
        Pr(\textsf{outcome is a}) = \sum_{b \in \Gamma} \left|\alpha_{ab}\right|^2 = \left\| \; \ket{\phi_a}\; \right\|^2
     $$     
     As a result of the standard basis measurement of $X$ giving the outcome $a$, the quantum state of $(X, Y)$ becomes
     $$
        \ket{a}\otimes \frac{\ket{\phi_a}}{\left\| \; \ket{\phi_a} \; \right\|}
     $$
     Here is an exmaple
     $$
        \ket{\psi}=\frac{1}{\sqrt{2}}\ket{00} + \frac{1}{2}\ket{01} + \frac{i}{2\sqrt{2}}\ket{10} - \frac{1}{2\sqrt{2}}\ket{11} = \ket{0} \otimes \left(\frac{1}{\sqrt{2}}\ket{0} + \frac{1}{2}\ket{1} \right) + \ket{1} \otimes \left( \frac{i}{2\sqrt{2}}\ket{0} - \frac{1}{2\sqrt{2}}\ket{1} \right)
     $$
     So the probability for measurement to result in the outcomes of $X$ being 0 and and 1 are 
     $$
        \left\| \braket{0}{\psi} \right\|^2=\left\| \frac{1}{\sqrt{2}}\ket{0} + \frac{1}{2}\ket{1} \right\|^2 = \frac{1}{2} + \frac{1}{4} \quad \textsf{ and } \quad \left\| \braket{1}{\psi} \right\|^2=\left\| \frac{i}{2\sqrt{2}}\ket{0} - \frac{1}{2\sqrt{2}}\ket{1} \right\|^2 = \frac{1}{8} + \frac{1}{8} = \frac{1}{4}
     $$
     And the corresponding state of $(X, Y)$ becomes
     $$
        \ket{0} \otimes \frac{\frac{1}{\sqrt{2}}\ket{0}+\frac{1}{2}\ket{1}}{\sqrt{\frac{3}{4}}} = \ket{0} \otimes \left(\sqrt{\frac{2}{3}}\ket{0}+ \frac{1}{\sqrt{3}}\ket{1}\right) = \sqrt{\frac{2}{3}}\ket{00}+ \frac{1}{\sqrt{3}}\ket{01} \quad \textsf{ and } \quad \ket{1} \otimes \frac{\frac{i}{2\sqrt{2}}\ket{0} - \frac{1}{2\sqrt{2}}\ket{1}}{\sqrt{\frac{1}{4}}} = \frac{i}{\sqrt{2}}\ket{10} - \frac{1}{\sqrt{2}}\ket{11}
     $$
     For measuring Y, we write
     $$
        \ket{\psi}=\frac{1}{\sqrt{2}}\ket{00} + \frac{1}{2}\ket{01} + \frac{i}{2\sqrt{2}}\ket{10} - \frac{1}{2\sqrt{2}}\ket{11} = \left(\frac{1}{\sqrt{2}}\ket{0} + \frac{i}{2\sqrt{2}}\ket{1}   \right) \otimes \ket{0} +   \left( \frac{1}{2}\ket{0} - \frac{1}{2\sqrt{2}}\ket{1} \right) \otimes \ket{1}
     $$     
     So the probability for measurement to result in the outcomes of $Y$ being 0 and and 1 are 
     $$
        \left\|\frac{1}{\sqrt{2}}\ket{0} + \frac{i}{2\sqrt{2}}\ket{1}   \right\|^2 = \frac{1}{2} + \frac{1}{8} = \frac{5}{8} \quad \textsf{ and } \quad \left\| \frac{1}{2}\ket{0} - \frac{1}{2\sqrt{2}}\ket{1}\right\| = \frac{1}{4}+\frac{1}{8}=\frac{3}{8}
     $$
     And the corresponding state of $(X, Y)$ becomes
     $$
        \frac{\frac{1}{\sqrt{2}}\ket{0} + \frac{i}{2\sqrt{2}}\ket{1}}{\sqrt{\frac{5}{8}}}\otimes \ket{0} = \sqrt{\frac{4}{5}}\ket{00}   \quad \textsf{ and } \quad \frac{\frac{1}{2}\ket{0} - \frac{1}{2\sqrt{2}}\ket{1}}{\sqrt{\frac{3}{8}}} \otimes \ket{1} = \sqrt{\frac{2}{3}}\ket{01} - \frac{1}{\sqrt{3}}\ket{11}
     $$
# Unitary Operations
  Suppose $X$ and $Y$ are qubits, performing a Hadmard operation on X and doing nothing on Y is equivalent to perform this unitary operation on $(X, Y)$
  $$
    \mathbb{H} \otimes \mathbb{1}
    = \begin{bmatrix}
    \; \frac{1}{\sqrt{2}} \qquad \frac{1}{\sqrt{2}} \; \\[8pt]
    \; \frac{1}{\sqrt{2}} \quad -\frac{1}{\sqrt{2}} \;
      \end{bmatrix} \otimes 
      \begin{bmatrix}
    \; 1 \quad 0 \;\\[8pt]  
    \; 0 \quad 1 \;
      \end{bmatrix}
    =\begin{align*} \begin{bmatrix}    
    \; &\frac{1}{\sqrt{2}}  &0                    &\frac{1}{\sqrt{2}}   &0 \; \\[8pt]
    \; &0                   &\frac{1}{\sqrt{2}}   &0                    &\frac{1}{\sqrt{2}}   \; \\[8pt]
    \; &\frac{1}{\sqrt{2}}  &0                    &-\frac{1}{\sqrt{2}}  &0 \; \\[8pt]
    \; &0                   &\frac{1}{\sqrt{2}}   &0                    &-\frac{1}{\sqrt{2}}  \; 
     \end{bmatrix} \end{align*}
  $$
  SWAP operation: $\textsf{SWAP}\ket{\phi \otimes \psi} = \ket{\psi \otimes \phi} $ and $\textsf{SWAP} = \sum_{a,b \in \Sigma} {\ketbra{a}{b} \otimes \ketbra{b}{a}}$. If $X$ and $Y$ are qubits, we find that
  $$
     \textsf{SWAP} = \begin{align*}  \begin{bmatrix}   
     \;1 &0 &0 &0 \; \\
     \;0 &0 &1 &0 \; \\
     \;0 &1 &0 &0 \; \\
     \;0 &0 &0 &1 \;  
     \end{bmatrix} \end{align*}
  $$
  Suppose $X$ is a quib and $Y$ is an arbitary system, for every unitary operation $\mathbb{U}$ on $Y$, a controlled-$\mathbb{U}$ is a unitary operation on the pair $(X,Y)$ defined as follows:  
  $$
    \ketbra{0}{0} \otimes \mathbb{1}_Y + \ketbra{1}{1} \otimes \mathbb{U} = \begin{align*}  \begin{bmatrix}  
    \; \mathbb{1}_Y \quad & \mathbb{0} \; \\[8pt]
    \; \mathbb{0}   \quad & \mathbb{U} \;
    \end{bmatrix} \end{align*}
  $$
  A controlled-NOT operation (where the first qubit is the control)
  $$
    \ketbra{0}{0} \otimes \mathbb{1} + \ketbra{1}{1} \otimes \sigma_x= \begin{align*}  \begin{bmatrix}  
     \;1 &0 &0 &0 \; \\
     \;0 &1 &0 &0 \; \\
     \;0 &0 &0 &1 \; \\
     \;0 &0 &1 &0 \;  
    \end{bmatrix} \end{align*}
  $$  
  A controlled-NOT operation (where the second qubit is the control)
  $$
    \mathbb{1} \otimes \ketbra{0}{0} + \sigma_x \otimes \ketbra{1}{1} = \begin{align*}  \begin{bmatrix}  
     \;1 &0 &0 &0 \; \\
     \;0 &0 &0 &1 \; \\
     \;0 &0 &1 &0 \; \\
     \;0 &1 &0 &0 \;  
    \end{bmatrix} \end{align*}
  $$  
  A controlled-$\sigma_z$ (or controlled-Z) operation (operation is same no matter the first or second is the control qubit )
  $$
    \ketbra{0}{0} \otimes \mathbb{1} + \ketbra{1}{1} \otimes \sigma_z= \mathbb{1} \otimes \ketbra{0}{0} + \sigma_z \otimes \ketbra{1}{1} =
    \begin{align*}  \begin{bmatrix}  
     \;1 &0 &0 &0 \; \\
     \;0 &1 &0 &0 \; \\
     \;0 &0 &1 &0 \; \\
     \;0 &0 &0 &-1 \;  
    \end{bmatrix} \end{align*}
  $$  
  A controlled-SWAP operation (on three qubits), also called $Fredkin$ operation (or $Fredkin$ gate)
  $$
    \ketbra{0}{0} \otimes \mathbb{1} + \ketbra{1}{1} \otimes \textsf{SWAP} = 
    \begin{align*}  \begin{bmatrix}  
     \;1 &0 &0 &0 &0 &0 &0 &0\; \\
     \;0 &1 &0 &0 &0 &0 &0 &0\; \\
     \;0 &0 &1 &0 &0 &0 &0 &0\; \\
     \;0 &0 &0 &1 &0 &0 &0 &0\; \\
     \;0 &0 &0 &0 &1 &0 &0 &0\; \\
     \;0 &0 &0 &0 &0 &0 &1 &0\; \\
     \;0 &0 &0 &0 &0 &1 &0 &0\; \\
     \;0 &0 &0 &0 &0 &0 &0 &1\; 
    \end{bmatrix} \end{align*}
  $$  
 
  A controlled-controlled-NOT operation (on three qubits), also called $Toffoli$ operation (or $Toffoli$ gate)
  $$
    \ketbra{0}{0} \otimes \mathbb{1} \otimes \mathbb{1}+ \ketbra{1}{1} \otimes \left(\ketbra{0}{0} \otimes \mathbb{1} + \ketbra{1}{1} \otimes \sigma_x \right) = 
    \begin{align*}  \begin{bmatrix}  
     \;1 &0 &0 &0 &0 &0 &0 &0\; \\
     \;0 &1 &0 &0 &0 &0 &0 &0\; \\
     \;0 &0 &1 &0 &0 &0 &0 &0\; \\
     \;0 &0 &0 &1 &0 &0 &0 &0\; \\
     \;0 &0 &0 &0 &1 &0 &0 &0\; \\
     \;0 &0 &0 &0 &0 &1 &0 &0\; \\
     \;0 &0 &0 &0 &0 &0 &0 &1\; \\
     \;0 &0 &0 &0 &0 &0 &1 &0\; 
    \end{bmatrix} \end{align*}
  $$  


# Named quantum states and operations
1. Bell states
    $$
      \ket{\phi^+} = \frac{1}{\sqrt{2}}\ket{00} + \frac{1}{\sqrt{2}}\ket{11}; \qquad \ket{\phi^-} = \frac{1}{\sqrt{2}}\ket{00} - \frac{1}{\sqrt{2}}\ket{11};  \qquad
      \ket{\psi^+} = \frac{1}{\sqrt{2}}\ket{01} + \frac{1}{\sqrt{2}}\ket{10}; \qquad \ket{\psi^-} = \frac{1}{\sqrt{2}}\ket{01} - \frac{1}{\sqrt{2}}\ket{10}  
    $$
    And
    $$
       \textsf{SWAP}\ket{\phi^+}  = \ket{\phi^+}; \qquad \textsf{SWAP}\ket{\phi^-}  = \ket{\phi^-}; \qquad \textsf{SWAP}\ket{\psi^+}  = \ket{\psi^+}; \qquad \textsf{SWAP}\ket{\psi^-}  = -\ket{\psi^-}
    $$
2. GHZ state
    $$
    \frac{1}{\sqrt{2}}\ket{000} + \frac{1}{\sqrt{2}}\ket{111}
    $$    
3. W state
    $$
    \frac{1}{\sqrt{3}}\ket{001} + \frac{1}{\sqrt{3}}\ket{010} + \frac{1}{\sqrt{3}}\ket{100}
    $$

